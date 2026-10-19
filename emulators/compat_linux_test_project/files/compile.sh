#!/bin/sh
#
#	install and compile LTP syscalls testes on NetBSD, using Compat Linux
#
# 	Requirements:
# 	- gmake
# 	- suse_gcc12-15.5
# 	- module compat_linux enabled

set -e

# ltp source directory
LTP_DIR="."

# Base directory for the syscalls subdirectory inside ltp
SYSCALL_DIR="${LTP_DIR}/testcases/kernel/syscalls"

RUNTEST_DIR="${LTP_DIR}/runtest"

# Directory where compiled tests will be placed
BINARIES_DIR="${DATA_DIR}"

# What compiler to use. Default searches for suse_gcc12-15.5
CC="/emul/linux/usr/bin/gcc-12"

# LTP Release version. Should be passed as argument
# Default is an empty string, which raises an error
LTP_RELEASE=""

# Available values: static dynamic
# The way the testcases should be compiled
LINK_MODE=""

# Flags used to minimize binary sizes
CFLAGS="-Os -fno-asynchronous-unwind-tables -fno-unwind-tables -fno-stack-protector"
LDFLAGS=""

check_gcc()
{
         ${CC} -v > /dev/null
         if [ $? != 0 ]; then
                 /sbin/modstat compat_linux | grep -q compat_linux
                 if [ $? = 0 ]; then
                         echo "Cannot run Linux gcc, but compat_linux is
loaded. Exiting"
                         return 1
                 fi
                 /sbin/modstat -e || exit 1
                 if [ $? != 0 ]; then
                         echo "Please run modload compat_linux as root"
                         return 1
                 fi
                 /sbin/modload compat_linux || exit 1
                 ${CC} -v > /dev/null
                 if [ $? != 0 ]; then
                         echo "Still unable to run Linux gcc. Exiting"
                         return 1
                 fi
         fi
         return 0
}

# Here we point PKG_CONFIG to /usr/bin/true to trick LTP's 'configure' script
# into thinking there is an adequate pkg-config.
# Compiling the syscalls testcases doesn't require the pkg-config, but
# 'configure' still stops if it cannot be found.

configure_static() {
	CFLAGS="${CFLAGS} -pthread"
	LDFLAGS="${LDFLAGS} -static -L${LTP_DIR}/lib -Wl,--whole-archive -lpthread -Wl,--no-whole-archive"

	./configure CC="${CC}" --prefix="${BINARIES_DIR}" \
		CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" \
		PKG_CONFIG="/usr/bin/true"
}

configure_dynamic() {
	CFLAGS="${CFLAGS} -ffunction-sections -fdata-sections"
	LDFLAGS="${LDFLAGS} -Wl,--gc-sections -s"

	./configure CC="${CC}" --prefix="${BINARIES_DIR}" \
 		CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" \
		PKG_CONFIG="/usr/bin/true"
}

compile_setup() {
	cd "${LTP_DIR}"

	if [ "${LINK_MODE}" = "dynamic" ]; then
		configure_dynamic
	elif [ "${LINK_MODE}" = "static" ]; then
		configure_static
	else
		echo "Invalid link mode: \"${LINK_MODE}\"" >&2
		exit 1
	fi

	gmake install -C "${LTP_DIR}/runtest" -j"$(sysctl -n hw.ncpu)"
}

compile_tests() {
	cd "${LTP_DIR}"

	gmake -C "${SYSCALL_DIR}/" -k -j"$(sysctl -n hw.ncpu)" CC="${CC}"
	gmake install -C "${SYSCALL_DIR}/" -j"$(sysctl -n hw.ncpu)" CC="${CC}"
}

# LTP has 2 runtest files related to syscalls, one generic and another only for
# IPC related syscalls.
# By joining them we can more easelly go throught both
join_runstest_files() {
	runtest_file="${RUNTEST_DIR}/syscalls"
	runtest_file_ipc="${RUNTEST_DIR}/syscalls-ipc" # LTP has another file just for IPC

	cat "${runtest_file}" > "${BINARIES_DIR}/syscalls-runtest"
	cat "${runtest_file_ipc}" >> "${BINARIES_DIR}/syscalls-runtest"
}

generate_syscall_index() {
	join_runstest_files

	index_file="${BINARIES_DIR}/syscall-index.txt"
	runtest_file="${BINARIES_DIR}/syscalls-runtest"

	: > "${index_file}"

	for dir in "${SYSCALL_DIR}"/*/; do
		syscall_name="$(basename "${dir}")"
		testcases_list=""

		for test_src in "${dir}"*.c; do
			if [ ! -e "${test_src}" ]; then
				continue
			fi

			testcase="$(basename "${test_src}" .c)"

			# Check if it is reconized as a test by the runtest_file
			if grep -q "^${testcase}[[:space:]]" "${runtest_file}"; then
				testcases_list="${testcases_list} ${testcase}"
			fi
		done

		# Skipps if empty (no tests found)
		if [ ! -n "${testcases_list}" ]; then
			continue
		fi

		echo "${syscall_name}${testcases_list}" >> "${index_file}"
	done
}

save_ltp_release() {
	echo "${LTP_RELEASE}" > "${BINARIES_DIR}/ltp-version.txt"
}

main() {

	while [ "$#" -gt 0 ]; do
		arg="$1"

		if [ "${arg}" = "--ltp-version" ]; then
			shift #consumes the arg
			LTP_RELEASE="$1" # uses the next
		elif [ "${arg}" = "--dest" ]; then
			shift
			BINARIES_DIR="$1"
		elif [ "${arg}" = "--link-mode" ]; then
			shift
			LINK_MODE="$1"
		else
			echo "Invalid Option: '${arg}'" >&2
			exit 1
		fi

		shift
	done

	if [ -z "${LTP_RELEASE}" ]; then
		echo "Error: No ltp-version was passed" >&2
		exit 1
	fi

	if [ -z "${BINARIES_DIR}" ]; then
		echo "Error: No dest was passed" >&2
		exit 1
	fi


	is_compat_linux_active() {
		[ "$(sysctl -n emul.linux.enabled 2>/dev/null)" = "1" ]
	}

	if ! is_compat_linux_active; then
		printf 'compat_linux is not active. Try modload compat_linux before running the script' >&2
	fi

	check_gcc || exit 1

	compile_setup
	compile_tests

	generate_syscall_index
	save_ltp_release
}

main "$@"
