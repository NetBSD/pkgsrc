#! /bin/sh
#
# Tests for mk/subst.mk.
#
set -eu

. "./test.subr"

test_case_set_up() {
	rm -rf "$tmpdir"/.??* "$tmpdir"/*

	create_file "prepare-subst.mk" <<EOF

# The tools that are used by subst.mk
CHMOD=		chmod-is-not-used
CMP=		cmp
ECHO=		echo
MKDIR=		mkdir -p
MV=		mv
RM=		rm
RMDIR=		rmdir
SED=		sed
TEST=		test
TOUCH=		touch
TOUCH_FLAGS=	# none
TR=		tr
TRUE=		true

# Commands that are specific to pkgsrc
RUN=		@set -e;
STEP_MSG=	echo "=>"
DO_NADA=	: do-nada
INFO_MSG=	echo "info:"
WARNING_MSG=	echo "warning:"
FAIL_MSG=	sh $PWD/$real_pkgsrcdir/mk/scripts/fail echo "fail:"

WRKDIR=		$tmpdir
WRKSRC=		$tmpdir
EOF
}


if test_case_begin "single file"; then

	# A single file is patched successfully.

	create_file "subst-single.mk" <<EOF
SUBST_CLASSES+=		class
SUBST_STAGE.class=	pre-configure
SUBST_FILES.class=	subst-single.txt
SUBST_SED.class=	-e 's,before,after,'

.include "prepare-subst.mk"
.include "mk/subst.mk"

all: subst-class
EOF

	create_file_lines "subst-single.txt" \
		"before"

	test_file "subst-single.mk" > "$tmpdir/output"

	assert_that "output" --file-contains-exactly "=> Substituting \"class\" in subst-single.txt"
	assert_that "subst-single.txt" --file-contains-exactly "after"

	test_case_end
fi


if test_case_begin "several individual files"; then

	# Several individual files are patched successfully.

	create_file "testcase.mk" <<EOF
SUBST_CLASSES+=		class
SUBST_STAGE.class=	pre-configure
SUBST_FILES.class=	first second third
SUBST_SED.class=	-e 's,file,example,'

.include "prepare-subst.mk"
.include "mk/subst.mk"

all: subst-class
EOF

	create_file_lines "first"	"the first file"
	create_file_lines "second"	"the second file"
	create_file_lines "third"	"the third file"

	output=$(test_file "testcase.mk")

	assert_that "$output" --equals "=> Substituting \"class\" in first second third"
	assert_that "first" --file-contains-exactly "the first example"
	assert_that "second" --file-contains-exactly "the second example"
	assert_that "third" --file-contains-exactly "the third example"

	test_case_end
fi


if test_case_begin "several files by pattern"; then

	# Several files are patched successfully.
	# The filenames are given by a pattern.

	create_file "testcase.mk" <<EOF
SUBST_CLASSES+=		class
SUBST_STAGE.class=	pre-configure
SUBST_FILES.class=	pattern-*
SUBST_SED.class=	-e 's,file,example,'

.include "prepare-subst.mk"
.include "mk/subst.mk"

all: subst-class
EOF

	create_file_lines "pattern-first"	"the first file"
	create_file_lines "pattern-second"	"the second file"
	create_file_lines "pattern-third"	"the third file"

	output=$(test_file "testcase.mk")

	assert_that "$output" --equals "=> Substituting \"class\" in pattern-*"
	assert_that "pattern-first" --file-contains-exactly "the first example"
	assert_that "pattern-second" --file-contains-exactly "the second example"
	assert_that "pattern-third" --file-contains-exactly "the third example"

	test_case_end
fi


if test_case_begin "pattern with 1 noop"; then

	# Several files are given via a pattern.
	# Most of the files are patched, but one stays the same.
	# Since it is easier to give a too broad pattern like *.py
	# than to exclude a few files from such a pattern,
	# only an info is logged.
	# This is not an error.

	create_file "testcase.mk" <<EOF
SUBST_CLASSES+=		class
SUBST_STAGE.class=	pre-configure
SUBST_FILES.class=	pattern-*
SUBST_SED.class=	-e 's,file,example,'

.include "prepare-subst.mk"
.include "mk/subst.mk"

all: subst-class
EOF

	create_file_lines "pattern-first"	"the first file"
	create_file_lines "pattern-second"	"the second is already an example"
	create_file_lines "pattern-third"	"the third file"

	test_file "testcase.mk" > "$tmpdir/actual-output"
	create_file_lines "expected-output" \
		'=> Substituting "class" in pattern-*' \
		'info: [subst.mk:class] Nothing changed in ./pattern-second.'

	assert_that "actual-output" --file-equals "expected-output"
	assert_that "pattern-first" --file-contains-exactly "the first example"
	assert_that "pattern-second" --file-contains-exactly "the second is already an example"
	assert_that "pattern-third" --file-contains-exactly "the third example"

	test_case_end
fi


if test_case_begin "single file noop, noop_ok=yes"; then

	create_file "testcase.mk" <<EOF
SUBST_CLASSES+=		class
SUBST_STAGE.class=	pre-configure
SUBST_FILES.class=	single
SUBST_SED.class=	-e 's,file,example,'
SUBST_NOOP_OK.class=	yes

.include "prepare-subst.mk"
.include "mk/subst.mk"

all: subst-class
EOF

	create_file_lines "single"	"already an example"

	test_file "testcase.mk" > "$tmpdir/actual-output" && exitcode=0 || exitcode=$?

	create_file_lines "expected-output" \
		'=> Substituting "class" in single' \
		'info: [subst.mk:class] Nothing changed in ./single.'
	assert_that "actual-output" --file-equals "expected-output"
	assert_that "single" --file-contains-exactly "already an example"
	assert_that "$exitcode" --equals "0"

	test_case_end
fi


if test_case_begin "single file noop, noop_ok=no"; then

	create_file "testcase.mk" <<EOF
SUBST_CLASSES+=		class
SUBST_STAGE.class=	pre-configure
SUBST_FILES.class=	single
SUBST_SED.class=	-e 's,file,example,'
SUBST_NOOP_OK.class=	no

.include "prepare-subst.mk"
.include "mk/subst.mk"

all: subst-class
EOF

	create_file_lines "single"	"already an example"

	test_file "testcase.mk" > "$tmpdir/actual-output" && exitcode=0 || exitcode=$?

	create_file_lines "expected-output" \
		'=> Substituting "class" in single' \
		'info: [subst.mk:class] Nothing changed in ./single.' \
		'fail: [subst.mk:class] The pattern single has no effect.' \
		'*** Error code 1' \
		'' \
		'Stop.' \
		"$make: stopped in $PWD"
	assert_that "actual-output" --file-equals "expected-output"
	assert_that "single" --file-contains-exactly "already an example"
	assert_that "$exitcode" --equals "1"

	test_case_end
fi


if test_case_begin "single file nonexistent"; then

	create_file "testcase.mk" <<EOF
SUBST_CLASSES+=		class
SUBST_STAGE.class=	pre-configure
SUBST_FILES.class=	nonexistent
SUBST_SED.class=	-e 's,file,example,'
SUBST_NOOP_OK.class=	no

.include "prepare-subst.mk"
.include "mk/subst.mk"

all: subst-class
EOF

	test_file "testcase.mk" > "$tmpdir/actual-output" && exitcode=0 || exitcode=$?

	create_file_lines "expected-output" \
		'=> Substituting "class" in nonexistent' \
		'warning: [subst.mk:class] Ignoring non-existent file "./nonexistent".' \
		'fail: [subst.mk:class] The pattern nonexistent has no effect.' \
		'*** Error code 1' \
		'' \
		'Stop.' \
		"$make: stopped in $PWD"
	assert_that "actual-output" --file-equals "expected-output"
	assert_that "$exitcode" --equals "1"

	test_case_end
fi


if test_case_begin "single file nonexistent ok"; then

	create_file "testcase.mk" <<EOF
SUBST_CLASSES+=		class
SUBST_STAGE.class=	pre-configure
SUBST_FILES.class=	nonexistent
SUBST_SED.class=	-e 's,file,example,'
SUBST_NOOP_OK.class=	yes

.include "prepare-subst.mk"
.include "mk/subst.mk"

all: subst-class
EOF

	test_file "testcase.mk" > "$tmpdir/actual-output" && exitcode=0 || exitcode=$?

	create_file_lines "expected-output" \
		'=> Substituting "class" in nonexistent' \
		'warning: [subst.mk:class] Ignoring non-existent file "./nonexistent".'
	assert_that "actual-output" --file-equals "expected-output"
	assert_that "$exitcode" --equals "0"

	test_case_end
fi


if test_case_begin "several patterns, 1 nonexistent"; then

	create_file "testcase.mk" <<EOF
SUBST_CLASSES+=		class
SUBST_STAGE.class=	pre-configure
SUBST_FILES.class=	*exist* *not-found*
SUBST_SED.class=	-e 's,file,example,'

.include "prepare-subst.mk"
.include "mk/subst.mk"

all: subst-class
EOF

	create_file_lines "exists"	"this file exists"

	test_file "testcase.mk" > "$tmpdir/actual-output" && exitcode=0 || exitcode=$?

	create_file_lines "expected-output" \
		'=> Substituting "class" in *exist* *not-found*' \
		'warning: [subst.mk:class] Ignoring non-existent file "./*not-found*".'
	assert_that "actual-output" --file-equals "expected-output"
	assert_that "exists" --file-contains-exactly "this example exists"
	assert_that "$exitcode" --equals "0"

	test_case_end
fi


if test_case_begin "multiple missing files, all are reported at once"; then

	create_file "testcase.mk" <<EOF
SUBST_CLASSES+=		class
SUBST_STAGE.class=	pre-configure
SUBST_FILES.class=	does not exist
SUBST_SED.class=	-e 'sahara'

.include "prepare-subst.mk"
.include "mk/subst.mk"
EOF

	test_file "testcase.mk" > "$tmpdir/actual-output" && exitcode=0 || exitcode=$?

	create_file_lines "expected-output" \
		'=> Substituting "class" in does not exist' \
		'warning: [subst.mk:class] Ignoring non-existent file "./does".' \
		'warning: [subst.mk:class] Ignoring non-existent file "./not".' \
		'warning: [subst.mk:class] Ignoring non-existent file "./exist".'
	assert_that "actual-output" --file-equals "expected-output"
	assert_that "$exitcode" --equals "0"

	test_case_end
fi


if test_case_begin "multiple no-op files, all are reported at once"; then

	create_file "testcase.mk" <<EOF
SUBST_CLASSES+=		class
SUBST_STAGE.class=	pre-configure
SUBST_FILES.class=	first second third
SUBST_SED.class=	-e 's,from,to,'

.include "prepare-subst.mk"
.include "mk/subst.mk"
EOF
	create_file_lines "first"	"text"
	create_file_lines "second"	"second"
	create_file_lines "third"	"third"

	test_file "testcase.mk" > "$tmpdir/actual-output" && exitcode=0 || exitcode=$?

	create_file_lines "expected-output" \
		'=> Substituting "class" in first second third' \
		'info: [subst.mk:class] Nothing changed in ./first.' \
		'info: [subst.mk:class] Nothing changed in ./second.' \
		'info: [subst.mk:class] Nothing changed in ./third.'
	assert_that "actual-output" --file-equals "expected-output"
	assert_that "$exitcode" --equals "0"

	test_case_end
fi


if test_case_begin "late evaluation of SUBST_FILES"; then

	# Ensure that SUBST_FILES is evaluated as late as possible.
	# Evaluating it early breaks cases like pkglocaledir where the
	# list of files is generated by a shell command.
	# See mk/configure/replace-localedir.mk.

	create_file "testcase.mk" <<EOF
REPLACE_FILES_CMD.class= \
	cd \${WRKSRC} && echo *r*

SUBST_CLASSES+=		class
SUBST_STAGE.class=	pre-configure
SUBST_FILES.class=	first third # \${REPLACE_FILES_CMD.class:sh}
SUBST_SED.class=	-e 's,from,to,'

.include "prepare-subst.mk"
RUN=		@set -e;
WRKSRC=		\${WRKDIR}/package-1.0
.include "mk/subst.mk"

# It is tricky that the dependency must use an internal implementation
# detail, but that's the only way to guarantee the correct ordering.
\${_SUBST_COOKIE.class}: prepare-subst-class
prepare-subst-class:
	\${RUN} \${MKDIR} \${WRKSRC}
	\${RUN} \${ECHO} "from" > "\${WRKSRC}/first"
	\${RUN} \${ECHO} "from" > "\${WRKSRC}/second"
	\${RUN} \${ECHO} "from" > "\${WRKSRC}/third"
EOF

	test_file "testcase.mk" "subst-class" \
		1> "$tmpdir/actual-output" \
		2> "$tmpdir/actual-stderr" \
	&& exitcode=0 || exitcode=$?

	create_file_lines "expected-output" \
		'=> Substituting "class" in first third'
	assert_that "actual-output" --file-equals "expected-output"
	assert_that "actual-stderr" --file-is-empty
	assert_that "package-1.0/first" --file-contains-exactly "to"
	assert_that "package-1.0/second" --file-contains-exactly "from"
	assert_that "package-1.0/third" --file-contains-exactly "to"
	assert_that "$exitcode" --equals "0"

	test_case_end
fi


if test_case_begin "special characters in filenames"; then

	create_file "testcase.mk" <<EOF
SUBST_CLASSES+=		class
SUBST_STAGE.class=	pre-configure
SUBST_FILES.class=	*
SUBST_SED.class=	-e s,before,after,
SUBST_NOOP_OK.class=	yes

.include "prepare-subst.mk"
.include "mk/subst.mk"
EOF

	create_file_lines " !\"#\$%&'()*+,-."	"before"
	create_file_lines "0123456789:;<=>?"	"before"
	create_file_lines "@ABCDEFGHIJKLMNO"	"before"
	create_file_lines "PQRSTUVWXYZ[\\]^_"	"before"
	create_file_lines "\`abcdefghijklmno"	"before"
	create_file_lines "pqrstuvwxyz{|}~"	"before"
	create_file_lines "--no-option"		"before"
	create_file_lines ".hidden"		"before"

	test_file "testcase.mk" "subst-class" \
		1> "$tmpdir/stdout" \
		2> "$tmpdir/stderr" \
	&& exitcode=0 || exitcode=$?

	assert_that "stdout" --file-is-lines \
		'=> Substituting "class" in *' \
		'info: [subst.mk:class] Nothing changed in ./prepare-subst.mk.' \
		'info: [subst.mk:class] Nothing changed in ./stderr.' \
		'info: [subst.mk:class] Nothing changed in ./stdout.' \
		'info: [subst.mk:class] Nothing changed in ./test.subr.main.mk.'
	assert_that "stderr" --file-is-empty
	assert_that "$exitcode" --equals "0"

	assert_that " !\"#\$%&'()*+,-."	--file-is-lines "after"
	assert_that "0123456789:;<=>?"	--file-is-lines "after"
	assert_that "@ABCDEFGHIJKLMNO"	--file-is-lines "after"
	assert_that "PQRSTUVWXYZ[\\]^_"	--file-is-lines "after"
	assert_that "\`abcdefghijklmno"	--file-is-lines "after"
	assert_that "pqrstuvwxyz{|}~"	--file-is-lines "after"
	assert_that "--no-option"	--file-is-lines "after"
	assert_that ".hidden"		--file-is-lines "before"

	test_case_end
fi

if test_case_begin "brackets in filename patterns"; then

	create_file "testcase.mk" <<EOF
SUBST_CLASSES+=		class
SUBST_STAGE.class=	pre-configure
SUBST_FILES.class=	[*]
SUBST_SED.class=	-e s,before,after,
SUBST_NOOP_OK.class=	yes

.include "prepare-subst.mk"
.include "mk/subst.mk"
EOF

	create_file_lines "any"	"before"
	create_file_lines "x"	"before"
	create_file_lines "*"	"before"
	create_file_lines "[*]"	"before"

	test_file "testcase.mk" "subst-class" \
		1> "$tmpdir/stdout" \
		2> "$tmpdir/stderr" \
	&& exitcode=0 || exitcode=$?

	assert_that "stdout" --file-is-lines \
		'=> Substituting "class" in [*]'
	assert_that "stderr" --file-is-empty
	assert_that "$exitcode" --equals "0"

	assert_that "any"	--file-is-lines "before"
	assert_that "x"		--file-is-lines "before"
	assert_that "*"		--file-is-lines "after"
	assert_that "[*]"	--file-is-lines "before"

	test_case_end
fi


if test_case_begin "duplicate SUBST class"; then

	create_file "testcase.mk" <<EOF
SUBST_CLASSES+=		one
SUBST_CLASSES+=		two
SUBST_CLASSES+=		one

all:
	@printf 'fail reason: %s\n' \${PKG_FAIL_REASON} 1>&2

.include "prepare-subst.mk"
.include "mk/subst.mk"
EOF

	test_file "testcase.mk" "all" \
		1> "$tmpdir/stdout" \
		2> "$tmpdir/stderr" \
	&& exitcode=0 || exitcode=$?

	assert_that "stdout" --file-is-empty
	assert_that "stderr" --file-is-lines \
		"fail reason: [subst.mk] duplicate SUBST class in: one one two"
	assert_that "$exitcode" --equals 0

	test_case_end
fi
