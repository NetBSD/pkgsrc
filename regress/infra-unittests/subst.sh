#! /bin/sh
#
# Tests for mk/subst.mk.
#
set -eu

. "./test.subr"

testcase() {
	test_name="$1"

	rm -rf "$tmpdir"/.subst_*_done "$tmpdir"/.subst-empty
	rm -rf "$tmpdir"/*
	ls -A "$tmpdir"

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


if testcase "single file"; then

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
fi


if testcase "several individual files"; then

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
fi


if testcase "several files by pattern"; then

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
fi


if testcase "pattern with 1 noop"; then

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
fi


if testcase "single file noop, noop_ok=yes"; then

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
fi


if testcase "single file noop, noop_ok=no"; then

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
fi


if testcase "single file nonexistent"; then

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
fi


if testcase "single file nonexistent ok"; then

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
fi


if testcase "several patterns, 1 nonexistent"; then

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
fi


if testcase "multiple missing files, all are reported at once"; then

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
fi


if testcase "multiple no-op files, all are reported at once"; then

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
fi

# TODO: Add test that ensures SUBST_FILES is evaluated as late as possible.
# Evaluating it early breaks cases like _pkglocaledir where the list of files
# is generated by a shell command. See mk/configure/replace-localedir.mk.

# TODO: Add tests for files having special characters, like space, dollar,
# backticks, basically every ASCII character.
