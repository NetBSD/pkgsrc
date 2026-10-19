#!/bin/sh
#
#	Run LTP syscall tests on NetBSD, using Compat Linux
#
# 	Requirements:
# 	- e2fsprogs (for ext* testing)
# 	- module compat_linux enabled

set -e

OS="$(uname -s)"
MAJOR="$(uname -r):C/\..*//}"
ARCH="$(uname -p)"

# Directory from where the script is being called
CALLING_DIR="$(pwd)"

# Directory where the script data is stored
DATA_DIR="/usr/pkg/libexec/compat_linux_test_project"

# Optional: Used to specify one syscall subdirectory inside SYSCALL_DIR
SYSCALL_NAME=""

# Optional: A comma-separated list of which syscalls to test. Should be parsed
# into individual SYSCALL_NAME
SYSCALLS_LIST=""

# Directory where compiled tests will be placed
BINARIES_DIR="${DATA_DIR}/testcases/bin"

# Index for helping with grouping testcases for syscall
# LTP uses the file-tree to group them, but we do not have access to the
# file-tree here
INDEX_FILE="${DATA_DIR}/syscall-index.txt"

# File with both runtest entries for 'syscalls' and 'syscalls-ipc'
# By joining them we can simplify work later, when iterating through them
RUNTEST_JOIN_FILE="${DATA_DIR}/syscalls-runtest"

# Directory where the output for the script are stored
OUTPUT_DIR=""
USER_DEFINED_OUTPUT_DIR=""

# Directory for the reference set of logs to be used in
# compare mode
REFERENCE_LOGS_DIR="${DATA_DIR}/reference_logs/${OS}-${MAJOR}-${ARCH}"

# Directory for the set of logs the user wants to compare
USER_DEFINED_LOGS_DIR=""

# How many lines the log header takes
# They all should have the same size, as they are created in a static style
# This may not be ideal, but there is no need to exchange this method with a
# runtime check
HEADER_LENGTH=10

# Script returns an error if the comparison found a change marked as 'regressions'
FAIL_ON_REGRESSION=0

# Temporary dir used to store runtime variables, like temporary block device
# Deleted upon exit
LTP_TMP_DIR=""

# Some tests require a block device to be present.
# The way LTP tries to get it does not work on NetBSD, so it is necessary
# to pass through a environment variable
VND_CONFIGURED=1
VND_IMAGE=""
VND_NAME="vnd0"
VND_DEVICE="/dev/r${VND_DEVICE}d"

# LTP environment variable.
# used to trim the tests' outputs to a more 'reproducible' style
LTP_REPRODUCIBLE_OUTPUT=0

# Some tests use the kernel config file to perform checks for some features.
# Here, we use a custom file to tell the tests which features are present.
# Note that the features is this file are not exhaustive, so some tests may ask
# for configuration not currently present in the file.
KCONFIG_PATH="${DATA_DIR}/linux_config"

# Some testcases verify if the operations were finished under
# a timer threshold. The LTP way of detecting if the system is
# a VM does not work on NetBSD.
# With this setting, we tell LTP to not check the tests against
# timers.
LTP_VIRT_OVERRIDE="kvm"

# If the script should save the core files, if any test crashes
# Note: for consistency with shell/exit-code convention, 0 means
# "yes/true" and 1 means "no/false" for the flag below
SAVE_CORE=1

# Recreation of the command and args used to run the script
_SCRIPT_INVOCATION=""

update_env_vars() {
	export LTPROOT="${DATA_DIR}"
	export PATH="${PATH}:${BINARIES_DIR}"
	export LTP_DEV="${BLK_DEV}"
	export LTP_REPRODUCIBLE_OUTPUT="${LTP_REPRODUCIBLE_OUTPUT}"
	export KCONFIG_PATH="${KCONFIG_PATH}"
	export LTP_VIRT_OVERRIDE="${LTP_VIRT_OVERRIDE}"
}

quote_args() {
	out=""
	for a in "$@"; do
		escaped=$(printf '%s' "$a" | sed "s/'/'\\\\''/g")
		out="${out} '${escaped}'"
	done
	printf '%s' "${out# }"
}

# Takes one argument: base_dir_name
# Loops through base_dir_name_1, base_dir_name_2, ..., base_dir_name_x until
# it finds a unused name.
next_unused_dir_name() {
	base_dir_name="$1"

	if [ ! -e "${base_dir_name}" ]; then
		printf '%s\n' "${base_dir_name}"
		return 0
	fi

	i=1

	while [ -e "${base_dir_name}_${i}" ]; do
		i=$((i + 1))
	done

	printf '%s\n' "${base_dir_name}_${i}"
}

print_help_message() {
	cat << EOF
NAME
	compat_linux_test_project - package to run LTP tests on NetBSD

SYNOPSIS
	compat_linux_test_project [options]

DESCRIPTION
	compat_linux_test_project is a package to download, build, and run
	the Linux Test Project (LTP) test suite on NetBSD, intended for
	testing	the compat_linux compatibility layer.

	It automates fetching, building, and executing LTP tests, helping
	to identify missing syscalls, behavioral differences, and other
	issues in NetBSD's Linux compatibility subsystem.

	If no --syscall option is passed, the default behavior is to test
	every possible syscall. This uses the LTP runtest/syscalls file to
	determine what to test and in which order. This means that the syscall
	name cannot be correctly-determined sometimes, resulting in suboptimal
	output in the logs. This also takes some time and is not
	recommended, except in some niche cases.

	All tests belong to Linux Testing Project, this package only ports
	them to	make them run on NetBSD. Support the Linux Test Project by
	checking their official website:
		https://github.com/linux-test-project/ltp

OPTIONS
	-d, --output-dir output_dir

		Directory where output is written.
		In test-run mode (default): new logs are stored here,
		overwriting any older logs already there.
		In comparison mode (-c): the categorized comparison results
		(compared_logs/) are stored here instead.

	-s, --syscall syscall1[,syscall2,...]
		A comma-separated list of which syscalls to test.
		The script will search for them using the LTP runtest file,
		so the name may be slightly different from the syscall name
		(though this is unusual).

		WARNING: some syscalls are excluded from the default (full)
		run because they are known to cause problems (e.g. kernel
		panics or hangs, see check_for_testcase_issue() in the
		script). If you explicitly list one of these syscalls here,
		the script will still run it, but will print a warning first.

	-r, --reproducible
		Sets the LTP environment variable LTP_REPRODUCIBLE_OUTPUT to 1.
		According to LTP documentation, this "suppress printing TINFO
		and TDEBUG messages and discards the actual content of the
		other messages printed by the test (suitable for a
		reproducible output)."

		This flag should be set if the logs are meant to be compared.

	-c, --compare logs_dir
		Compares logs_dir against a baseline, highlighting
		their differences. For a consistent comparison, both
		sets of logs should have been gathered using the
		'reproducible' mode ('-r' flag).

		The baseline defaults to the reference logs shipped with the
		package, or to whatever is passed via '-b'.

		If '-s' is also passed, the comparison is restricted to the
		syscalls listed there.

		The comparison is done as follows:
		Checks for tests that are new, tests that are no longer
		present, and tests whose result changed. Changed results are
		further split into regressions (e.g. PASS -> FAIL), fixes
		(e.g. FAIL -> PASS) and	other changes (e.g. shift in skipped
		or warnings). Some testcases are known to depend on
		functionality with no equivalent in NetBSD and are marked
		as wont_test.

		Each category is stored in its own subdirectory, mirroring the
		syscall/testcase layout of the compared logs:
			compared_logs/
			|-- changed/
			|-- fixed/
			|-- new/
			|-- regressed/
			|-- removed/
			|   |-- syscall_a/
			|       |- testcase01.log
			|-- wont_test/

		Each generated testcase01.log file is self-contained:
		- For 'new'/'removed' testcases, it has a short status line
		  followed by the full content of the one log that exists
		  (current or reference, respectively).
		- For 'changed'/'fixed'/'regressed' testcases, it has the
		  reference and current pass/failed/broken/skipped/warnings
		  counts, followed by the full content of both the reference
		  and the current log.
		This means you normally do not need to go dig through the
		original sys_logs/ or reference logs directories to
		investigate a specific resuls.

		The comparison assumes the testcases output follows the
		standard and new LTP structure. This is not true for every
		testcase, in this case, the comparison has undefined
		behavior.

	-b, --baseline logs_dir
		Directory with the logs to use as baseline. Only meaningful
		together with '-c'. Defaults to the reference logs shipped
		with the package.

	--fail-on-regression
		Only meaningful together with -c.
		When this flag is set, the script exits with a non-zero status
		if any test is found in compared_logs/regressed/. This is
		intended for use by automated testing.
		Has no effect without -c.

	--save-core
		By default, core dumps are disabled while the tests run.
		When this flag is set, the kernel writes the core files
		as usual, usually in the current directory.
		Has no effect in comparison mode (-c).

	-h, --help
		Shows this message
EOF
}

create_temp_dir() {
	# Remove leftovers of previous runs
	rm -rf "/var/tmp/compat_ltp".*

	LTP_TMP_DIR="$(mktemp -d "/var/tmp/compat_ltp.XXXXXX")" || exit 1
}

delete_temp_dir() {
	if [ -n "${LTP_TMP_DIR}" ]; then
		rm -rf "${LTP_TMP_DIR:?}"
	fi
	LTP_TMP_DIR=""
}

# Creates a fresh image for the block device used by some testcases.
create_block_file() {
	VND_IMAGE="${LTP_TMP_DIR}/test.img"
	dd if=/dev/zero of="${VND_IMAGE}" bs=1m count=512
}

mount_ltp_dev() {
	# Do not touch the vnd if it is already in use.
	vnd_state="$(vnconfig -l "${VND_NAME}" 2>&1 || true)"

	if [ "${vnd_state}" != "${VND_NAME}: not in use" ]; then
		printf '%s\n' "${VND_NAME} is not available: ${vnd_state}" >&2
		printf '%s\n' "Did you stop mid-test? Try running 'vnconfig -u ${VND_NAME}' to free it up, then re-run this script." >&2
		exit 1
	fi

	# Register the cleanup before creating anything
	trap unmount_ltp_dev EXIT
	trap 'exit 129' HUP
	trap 'exit 130' INT
	trap 'exit 143' TERM

	create_block_file

	printf '%s\n' "Mounting block device ${VND_NAME} from image ${VND_IMAGE}..."
	vnconfig "${VND_NAME}" "${VND_IMAGE}"
	VND_CONFIGURED=0
}

# Safe to call more than once, and with nothing set up yet.
unmount_ltp_dev() {
	if [ "${VND_CONFIGURED}" -eq 0 ]; then
		# Marked first, so the vnd is never released twice
		VND_CONFIGURED=1

		printf '%s\n' "Unmounting block device ${VND_NAME}..."
		vnconfig -u "${VND_NAME}"
	fi

	# Removed even if the vnd could not be released
	delete_temp_dir
}

create_output_dir() {
	dir_name="$1"

	# If the user passed the output dir, do not try to change
	# the name
	if [ ! -z "${USER_DEFINED_OUTPUT_DIR}" ]; then
		OUTPUT_DIR="${USER_DEFINED_OUTPUT_DIR}"

	else
		base_logs_dir="$(next_unused_dir_name  "${dir_name}")"

		OUTPUT_DIR="${CALLING_DIR}/${base_logs_dir}"
	fi

	mkdir -p "${OUTPUT_DIR}"
	printf '%s\n' "Output will be stored in: ${OUTPUT_DIR}"
}

# Header stores some useful data about the enviroment in which the tests
# ran. It can be useful to track down issues:
#
# ---- compat_linux_test_project log header ----
# date: Fri, 14 Aug 2026 00:09:27 +0000
# netbsd_version: 11.0_RC5
# netbsd_build: NetBSD 11.0_RC5 (GENERIC) #0: Tue Jun 16 15:48:07 UTC
# 2026  mkrepro@mkrepro.NetBSD.org:/usr/src/sys/arch/amd64/compile/GENERIC
# arch: amd64
# ltp_version: 20260529
# script_invocation: "/usr/pkg/bin/compat_linux_test_project '-r' '-s' 'readv,writev'"
# syscall_tested: readv
# reproducible: 1
# --------------------------------------------------
log_header() {
	syscall_tested="$1"

	curr_date="$(date -uR)"
	kernel_version="$(uname -r)"
	kernel_build="$(uname -v)"
	arch="$(uname -m)"
	ltp_version="$(cat ${DATA_DIR}/ltp-version.txt)"

	cat << EOF
---- compat_linux_test_project log header ----
date: ${curr_date}
netbsd_version: ${kernel_version}
netbsd_build: ${kernel_build}
arch: ${arch}
ltp_version: ${ltp_version}
script_invocation: "${_SCRIPT_INVOCATION}"
syscall_tested: ${syscall_tested}
reproducible: ${LTP_REPRODUCIBLE_OUTPUT}
--------------------------------------------------

EOF
}

# Runs a given testcase and outputs their result into the output file
run_testcase() {
	test_name="$1"
	test_bin="$2"
	syscall_tested="$3"
	test_args="$4"

	output_file="${syscall_dir}/${test_name}.log"

	# Prints the header for the logs
	# Clears the file if it was present
	log_header "${syscall_tested}" > "${output_file}"

	set -- ${test_args} # word splitting is desired

	printf '%s\n' "syscall_test: ${test_bin}"

	set -o pipefail

	test_status=0
	"${BINARIES_DIR}/${test_bin}" "$@" 2>&1 | tee -a "${output_file}" || test_status="$?"

	set +o pipefail

	# Something went wrong and the test was killed by a signal
	if [ "${test_status:-0}" -ge 128 ]; then
		printf '\nTESTCASE CRASHED: exit status %s (signal %s)\n' \
			"${test_status}" "$((test_status - 128))" >> "${output_file}"
	fi
}

check_for_testcase_issue() {
	syscall_name="$1"

	# The user explicitly asked to test this exact syscall (via -s/--syscall),
	# so we let it run even if it is on the "known issues" list below.
	# We still warn loudly, since a couple of these are known to panic the
	# kernel rather than just fail or hang.
	if [ "${syscall_name}" = "${SYSCALL_NAME}" ]; then
		case "${syscall_name}" in
			rt_sigqueueinfo|copy_file_range)
				msg="WARNING: '${syscall_name}' is known to cause a KERNEL PANIC under compat_linux."
				msg="${msg} Running it anyway because it was explicitly requested with -s/--syscall."
				msg="${msg} Make sure any important work is saved."
				printf '%s\n' "${msg}" >&2
				;;
			sigprocmask|sigrelse)
				msg="WARNING: '${syscall_name}' is known to hang and never finish under compat_linux."
				msg="${msg} Running it anyway because it was explicitly requested with -s/--syscall."
				printf '%s\n' "${msg}" >&2
				;;
		esac
		return 0
	fi

	case "${syscall_name}" in
		# causes kernel panic
		rt_sigqueueinfo)
			return 1
			;;
		# causes kernel panic
		copy_file_range)
			return 1
			;;
		# Does not finish
		sigprocmask)
			return 1
			;;
		# Does not finish
		sigrelse)
			return 1
			;;
		*)
			return 0
			;;
	esac
}

# Some tests that have known issues in compat_linux, for
# various reasons and would not be relevant to test under
# normal circunstances
check_for_wont_test() {
	syscall_name="$1"
	testcase_name="$2"

	wont_test_cases="futex_wake04 mmap10 recvmsg03 shmctl03 fork05"

	# The user explicitly asked to test this exact syscall (via -s/--syscall). Do not skip.
	if [ "${syscall_name}" = "${SYSCALL_NAME}" ]; then
		return 0
	fi
	for testcase in ${wont_test_cases}; do
		if [ "${testcase}" = "${testcase_name}" ]; then
			return 1
		fi
	done
	return 0
}

# Runs all testcases for a given syscall, if one provided as argument.
# Otherwise, goes through all syscalls and testcases listed in the index
run_testcases() {
	syscall="$1"
	sys_filter="$(basename "${syscall}")" # name of the syscall passed

	runtest_syscalls_file="${RUNTEST_JOIN_FILE}"

	if [ -n "${sys_filter}" ]; then
		printf '%s\n' "==> Testing syscall: ${sys_filter}"
	else
		printf '%s\n' "==> No syscall filter given, testing every syscall in the index (this can take a long time)"
	fi

	cat "${INDEX_FILE}" | while read -r syscall_name testcases; do

		# skips the lines that do not match sys_filter, unless it is empty
		if [ -n "${sys_filter}" ] && [ "${syscall_name}" != "${sys_filter}" ]; then
			continue
		fi

		# skips tests that are known to cause issues
		if ! check_for_testcase_issue "${syscall_name}"; then
			msg="Skipping syscall '${syscall_name}': known to cause issues, see check_for_testcase_issue()"
			msg="${msg} (use -s ${syscall_name} to force it)"
			printf '%s\n' "${msg}"
			continue
		fi

		# When iterating through the whole index, let the user know which
		# syscall is currently being tested
		if [ -z "${sys_filter}" ]; then
			printf '%s\n' "  -> ${syscall_name}"
		fi

		syscall_dir="${OUTPUT_DIR}/${syscall_name}"

		# Clears previous logs, if any
		if [ -e "${syscall_dir:?}" ]; then
			rm -rf "${syscall_dir:?}"/* 2>/dev/null || true
		else
			mkdir -p "${syscall_dir}"
		fi

		for testcase in ${testcases}; do

			# '|| true' avoids aborting the whole script (set -e) if the
			# index and the runtest file ever get out of sync for a given
			# testcase; we warn and skip that single testcase instead.
			runtest_line="$(grep "^${testcase}[[:space:]]" "${runtest_syscalls_file}" || true)"

			if [ -z "${runtest_line}" ]; then
				msg="WARNING: no entry found for testcase '${testcase}' (syscall '${syscall_name}')"
				msg="${msg} in ${runtest_syscalls_file}, skipping"
				printf '%s\n' "${msg}" >&2
				continue
			fi

			set -- ${runtest_line} # word-splitting is desired

			test_name="$1"
			test_bin="$2"
			shift 2

			run_testcase "${test_name}" "${test_bin}" "${syscall_name}" "$*"
		done
	done
}

run_tests() {

	create_temp_dir

	printf '%s\n' "Preparing block device required by some testcases..."
	mount_ltp_dev

	printf '%s\n' "Starting test run. This may take a while..."

	create_output_dir "sys_logs"

	if [ "${SAVE_CORE}" -eq 0 ]; then
		ulimit -S -c 0
	fi

	if [ -z "${SYSCALLS_LIST}" ]; then
		# user did not specify which syscall to test. Test them all
		run_testcases
	else
		# User specified syscalls to test
		# Go through each one and test their testcases
		syscall_list_parsed=$(echo "${SYSCALLS_LIST}" | sed "s/,/ /g")

		for s_name in ${syscall_list_parsed}; do
			SYSCALL_NAME="${s_name}"

			run_testcases "${SYSCALL_NAME}"
		done
	fi

	unmount_ltp_dev

	printf '%s\n' "Test run finished. Logs stored in: ${OUTPUT_DIR}"
}

# Get the 'header' inside dir/*/*.log (does not check if it is, in fact, a log
# header)
get_representative_log() {
	dir="$1"
	find "${dir}" -mindepth 2 -maxdepth 2 -type f -name '*.log' | head -n 1
}

# Creates the header for the comparison
# This header is made up of both headers from the reference and current sets of
# logs, warnings, whether both headers have some key different values and a
# brief summary of the results.
compare_create_header() {
	reference_logs_dir="$1"
	current_logs_dir="$2"

	reference_sample="$(get_representative_log "${reference_logs_dir}")"
	current_sample="$(get_representative_log "${current_logs_dir}")"

	if [ -z "${current_sample}" ] || [ -z "${reference_sample}" ]; then
		printf "Cannot build comparison summary: no log files found in one of the sets\n" >&2
		exit 1
	fi

	current_header="$(head -n "${HEADER_LENGTH}" "${current_sample}")"
	reference_header="$(head -n "${HEADER_LENGTH}" "${reference_sample}")"

	{
		printf '==================================================\n'
		printf '   COMPARISON SUMMARY\n'
		printf '==================================================\n\n'

		printf 'reference set: %s \n' "${reference_logs_dir}"
		printf '%s\n\n' "${reference_header}"

		printf 'current set: %s \n' "${current_logs_dir}"
		printf '%s\n\n' "${current_header}"
	} > "${OUTPUT_DIR}/summary.log"

	# Checks for some fields that *may* be relevant (or even invalidate) some
	# tests comparisons. Outputs a warning for them.
	for field in netbsd_version arch ltp_version reproducible; do

		reference_val="$(printf '%s\n' "${reference_header}" | sed -n "s/^${field}: //p")"
		current_val="$(printf '%s\n' "${current_header}" | sed -n "s/^${field}: //p")"

		if [ "${reference_val}" != "${current_val}" ]; then
			printf 'WARNING: %s differs (reference: "%s", current: "%s")\n' \
				"${field}" "${reference_val}" "${current_val}" >> "${OUTPUT_DIR}/summary.log"
		fi
	done
}

# Counts how many cases were found for each comparison category
compare_append_counts() {
	{
		printf '\n'
		printf '==================================================\n'
		printf '   RESULTS\n'
		printf '==================================================\n'
		printf '\n'

		for category in regressed fixed changed new removed wont_test; do
			count="$(find "${OUTPUT_DIR}/${category}" -type f -name '*.log' 2>/dev/null | wc -l)"
			printf '%-10s %s\n' "${category}:" "${count}"
		done
	} >> "${OUTPUT_DIR}/summary.log"
}

# Extracts the values of the results and returns them in a single line
compare_extract_summary() {
	file="$1"
	awk '
		/^passed[[:space:]]/   { passed = $2 }
		/^failed[[:space:]]/   { failed = $2 }
		/^broken[[:space:]]/   { broken = $2 }
		/^skipped[[:space:]]/  { skipped = $2 }
		/^warnings[[:space:]]/ { warnings = $2 }
		END { print passed, failed, broken, skipped, warnings }
	' "${file}"
}

# Builds one self-contained diff log for a testcase: a short status/summary
# header, followed by the full content of whichever log(s) are available.
# This is what gets written under diff_logs/<category>/<syscall>/<testcase>.log
compare_testcase() {
	reference_file="$1"
	current_file="$2"
	syscall_name="$3"
	testcase_name="$4"

	# This testcase is not present in the reference logs, so it is 'new'
	if [ ! -e "${reference_file}" ]; then
		mkdir -p "${OUTPUT_DIR}/new/${syscall_name}"

		out_file="${OUTPUT_DIR}/new/${syscall_name}/${testcase_name}.log"

		{
			printf 'testcase: %s\n' "${testcase_name}"
			printf 'status: new (not present in the reference set)\n\n'
			printf -- '---- current log (%s) ----\n' "${current_file}"
			cat "${current_file}"
		} > "${out_file}"

		return
	fi

	# This testcase is not present in the current logs, so it was 'removed'
	if [ ! -e "${current_file}" ]; then
		mkdir -p "${OUTPUT_DIR}/removed/${syscall_name}"

		out_file="${OUTPUT_DIR}/removed/${syscall_name}/${testcase_name}.log"

		{
			printf 'testcase: %s\n' "${testcase_name}"
			printf 'status: removed (not present in the current set)\n\n'
			printf -- '---- reference log (%s) ----\n' "${reference_file}"
			cat "${reference_file}"
		} > "${out_file}"

		return
	fi

	r_summary="$(compare_extract_summary "${reference_file}")"
	c_summary="$(compare_extract_summary "${current_file}")"

	# Nothing to when both testcases have the same output
	[ "${r_summary}" = "${c_summary}" ] && return

	# By 'bad', we mean the sum of the 'failed' + 'broken' fields
	r_bad="$(printf '%s' "${r_summary}" | awk '{print $2+$3}')"
	c_bad="$(printf '%s' "${c_summary}" | awk '{print $2+$3}')"

	if check_for_wont_test "${syscall_name}" "${testcase_name}"; then
		category="wont_test"
	elif [ "${c_bad}" -gt "${r_bad}" ]; then
		category="regressed"
	elif [ "${c_bad}" -lt "${r_bad}" ]; then
		category="fixed"
	else
		# A testcase is marked as 'changed' when there is a difference in its
		# 'skipped' or/and 'warnings' ltp fields
		# We may want to look closer to why this happened
		category="changed"
	fi

	mkdir -p "${OUTPUT_DIR}/${category}/${syscall_name}"

	out_file="${OUTPUT_DIR}/${category}/${syscall_name}/${testcase_name}.log"

	{
		printf 'testcase: %s\n' "${testcase_name}"
		printf '  reference (passed failed broken skipped warnings): %s\n' "${r_summary}"
		printf '  current   (passed failed broken skipped warnings): %s\n\n' "${c_summary}"
		printf -- '---- reference log (%s) ----\n' "${reference_file}"
		cat "${reference_file}"
		printf -- '\n---- current log (%s) ----\n' "${current_file}"
		cat "${current_file}"
	} > "${out_file}"
}

compare_tests() {
	current_logs_dir="${USER_DEFINED_LOGS_DIR}"
	reference_logs_dir="${REFERENCE_LOGS_DIR}"

	# Cannot compare if one directory does not exist
	if [ ! -e "${current_logs_dir}" ]; then
		printf "Nothing to be compared, '%s' not found\n" "${current_logs_dir}" >&2
		exit 1
	elif [ ! -e "${reference_logs_dir}" ]; then
		printf "Nothing to be compared, '%s' not found\n" "${reference_logs_dir}" >&2
		exit 1
	fi

	create_output_dir "diff_logs"

	printf '%s\n' "Comparing logs:"
	printf '%s\n' "  reference: ${reference_logs_dir}"
	printf '%s\n' "  current:   ${current_logs_dir}"

	compare_create_header "${reference_logs_dir}" "${current_logs_dir}"

	# Allow the user to pass which syscall should be compared
	if [ -n "${SYSCALLS_LIST}" ]; then
		all_syscalls="$(echo "${SYSCALLS_LIST}" | tr ',' '\n' | sort -u)"
	else
		all_syscalls="$( (ls "${reference_logs_dir}"; ls "${current_logs_dir}") | sort -u)"
	fi

	printf '%s\n' "Analyzing testcases, this may take a while for large log sets..."

	for syscall in ${all_syscalls}; do

		r_dir="${reference_logs_dir}/${syscall}"
		c_dir="${current_logs_dir}/${syscall}"

		# redirect the error logs to /dev/null. With this, the user won't see
		# anything if a syscall dir is empty. (In case of a new/remove syscall
		# between the reference and the current logs)
		all_testcases="$(\
            (ls "${r_dir}" 2>/dev/null || true; ls "${c_dir}" 2>/dev/null || true) \
            | sort -u)"

		for tc_file in ${all_testcases}; do
			testcase="${tc_file%.log}"

			compare_testcase "${r_dir}/${tc_file}" "${c_dir}/${tc_file}" \
				"${syscall}" "${testcase}"
		done

	done

	compare_append_counts

	printf '%s\n' "Comparison finished. Full summary saved to: ${OUTPUT_DIR}/summary.log"
	printf '\n'

	cat "${OUTPUT_DIR}/summary.log"
}

main() {
	_SCRIPT_INVOCATION="$0 $(quote_args "$@")"

	# Note: for consistency with shell/exit-code convention, 0 means
	# "yes/true" and 1 means "no/false" for both flags below.
	should_print_help_message=1
	compare_mode=1

	while [ "$#" -gt 0 ]; do
		arg="$1"

		case "${arg}" in
			-s|--syscall)
				shift # consumes the flag
				SYSCALLS_LIST="$1" # uses the next
				;;
			-d|--output-dir)
				shift # consumes the flag
				USER_DEFINED_OUTPUT_DIR="$1" # uses the next
				;;
			-h|--help)
				should_print_help_message=0
				;;
			-r|--reproducible)
				LTP_REPRODUCIBLE_OUTPUT=1
				;;
			-c|--compare)
				shift # consumes the flag
				USER_DEFINED_LOGS_DIR="$1"
				compare_mode=0
				;;
			-b|--baseline)
				shift # consumes the flag
				REFERENCE_LOGS_DIR="$1"
				compare_mode=0
				;;
			--fail-on-regression)
				FAIL_ON_REGRESSION=1
				;;
			--save-core)
				SAVE_CORE=0
				;;
			*)
				printf '%s\n' "Invalid Option: '${arg}'" >&2
				exit 1
				;;
		esac
		shift
	done

	if [ "${should_print_help_message}" -eq 0 ]; then
		print_help_message
		return
	fi

	update_env_vars

	is_root() {
		[ "$(id -u)" -eq 0 ]
	}

	if ! is_root; then
		printf 'This script should be run as root.\n' >&2
		printf 'Many Linux Test Project tests do not run well witout root\n' >&2
	fi

	is_compat_linux_active() {
		[ "$(sysctl -n emul.linux.enabled 2>/dev/null)" = "1" ]
	}

	if ! is_compat_linux_active; then
		printf 'compat_linux is not active. Try modload compat_linux before running the script\n' >&2
		exit 1
	fi

	if [ "${compare_mode}" -eq 0 ]; then
		compare_tests
	else
		run_tests
	fi

	if [ "${compare_mode}" -eq 0 ] && [ "${FAIL_ON_REGRESSION}" -eq 1 ]; then
		regressions="$(find "${OUTPUT_DIR}/regressed" -type f -name '*.log' 2>/dev/null | wc -l)"
		if [ "${regressions}" -gt 0 ]; then
			printf '%s\n' "FAIL_ON_REGRESSION: found ${regressions} regression(s), exiting with an error." >&2
			exit 1
		fi
	fi

	if [ "${compare_mode}" -eq 1 ] && [ "${FAIL_ON_REGRESSION}" -eq 1 ]; then
		printf '%s\n' "Flag 'FAIL_ON_REGRESSION' is being used outside comparison mode. This flag has no effect outside comparison mode." >&2
	fi
}

main "$@"
