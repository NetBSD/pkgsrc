#! /bin/sh
# $NetBSD: subst.sh,v 1.32 2020/05/06 06:14:56 rillig Exp $
#
# Tests for mk/subst.mk.
#

set -eu

. "./test.subr"

test_case_set_up() {
	rm -rf "$tmpdir"/.??* "$tmpdir"/*

	create_file "prepare-subst.mk" <<EOF

# The tools that are used by subst.mk
AWK=		awk
CHMOD=		chmod
CMP=		cmp
DIFF=		diff
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
FAIL_MSG=	sh $pkgsrcdir/mk/scripts/fail echo "fail:"

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

	run_bmake "subst-single.mk" > "$tmpdir/output"

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

	output=$(run_bmake "testcase.mk")

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

	output=$(run_bmake "testcase.mk")

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

	run_bmake "testcase.mk" > "$tmpdir/actual-output"
	create_file_lines "expected-output" \
		'=> Substituting "class" in pattern-*' \
		'info: [subst.mk:class] Nothing changed in "pattern-second".'

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

	run_bmake "testcase.mk" > "$tmpdir/actual-output" && exitcode=0 || exitcode=$?

	create_file_lines "expected-output" \
		'=> Substituting "class" in single' \
		'info: [subst.mk:class] Nothing changed in "single".'
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

	run_bmake "testcase.mk" > "$tmpdir/actual-output" && exitcode=0 || exitcode=$?

	create_file_lines "expected-output" \
		'=> Substituting "class" in single' \
		'warning: [subst.mk:class] Nothing changed in "single".' \
		'fail: [subst.mk:class] The filename pattern "single" has no effect.' \
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

	run_bmake "testcase.mk" > "$tmpdir/actual-output" && exitcode=0 || exitcode=$?

	create_file_lines "expected-output" \
		'=> Substituting "class" in nonexistent' \
		'warning: [subst.mk:class] Ignoring nonexistent file "nonexistent".' \
		'fail: [subst.mk:class] The filename pattern "nonexistent" has no effect.' \
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

	run_bmake "testcase.mk" > "$tmpdir/actual-output" && exitcode=0 || exitcode=$?

	create_file_lines "expected-output" \
		'=> Substituting "class" in nonexistent' \
		'info: [subst.mk:class] Ignoring nonexistent file "nonexistent".'
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

	run_bmake "testcase.mk" > "$tmpdir/actual-output" && exitcode=0 || exitcode=$?

	create_file_lines "expected-output" \
		'=> Substituting "class" in *exist* *not-found*' \
		'info: [subst.mk:class] Ignoring nonexistent file "./*not-found*".'
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

	run_bmake "testcase.mk" > "$tmpdir/actual-output" && exitcode=0 || exitcode=$?

	create_file_lines "expected-output" \
		'=> Substituting "class" in does not exist' \
		'info: [subst.mk:class] Ignoring nonexistent file "does".' \
		'info: [subst.mk:class] Ignoring nonexistent file "not".' \
		'info: [subst.mk:class] Ignoring nonexistent file "exist".'
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

	run_bmake "testcase.mk" > "$tmpdir/actual-output" && exitcode=0 || exitcode=$?

	create_file_lines "expected-output" \
		'=> Substituting "class" in first second third' \
		'info: [subst.mk:class] Nothing changed in "first".' \
		'info: [subst.mk:class] Nothing changed in "second".' \
		'info: [subst.mk:class] Nothing changed in "third".'
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

	run_bmake "testcase.mk" "subst-class" \
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

	run_bmake "testcase.mk" "subst-class" \
		1> "$tmpdir/stdout" \
		2> "$tmpdir/stderr" \
	&& exitcode=0 || exitcode=$?

	assert_that "stdout" --file-is-lines \
		'=> Substituting "class" in *' \
		'info: [subst.mk:class] Nothing changed in "prepare-subst.mk".' \
		'info: [subst.mk:class] Nothing changed in "stderr".' \
		'info: [subst.mk:class] Nothing changed in "stdout".' \
		'info: [subst.mk:class] Nothing changed in "test.subr.main.mk".'
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

	run_bmake "testcase.mk" "subst-class" \
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

	run_bmake "testcase.mk" "all" \
		1> "$tmpdir/stdout" \
		2> "$tmpdir/stderr" \
	&& exitcode=0 || exitcode=$?

	assert_that "stdout" --file-is-empty
	assert_that "stderr" --file-is-lines \
		"fail reason: [subst.mk] duplicate SUBST class in: one one two"
	assert_that "$exitcode" --equals 0

	test_case_end
fi


if test_case_begin "several SUBST classes"; then

	# It's ok to have several SUBST classes that apply to the same file.
	# The order of execution is not guaranteed though.

	create_file_lines "file" "zero one two three four"

	create_file "testcase.mk" <<EOF
SUBST_CLASSES+=		one
SUBST_STAGE.one=	pre-configure
SUBST_FILES.one=	file
SUBST_SED.one=		-e 's,one,I,'

SUBST_CLASSES+=		two
SUBST_STAGE.two=	pre-configure
SUBST_FILES.two=	file
SUBST_SED.two=		-e 's,two,II,'

SUBST_CLASSES+=		three
SUBST_STAGE.three=	pre-configure
SUBST_FILES.three=	file
SUBST_SED.three=	-e 's,three,III,'

.include "prepare-subst.mk"
.include "mk/subst.mk"
EOF

	run_bmake "testcase.mk" "pre-configure" \
		1> "$tmpdir/stdout" \
		2> "$tmpdir/stderr" \
	&& exitcode=0 || exitcode=$?

	# The order of the above output is not guaranteed.
	LC_ALL=C sort < "$tmpdir/stdout" > "$tmpdir/stdout-sorted"

	assert_that "file" --file-is-lines "zero I II III four"
	assert_that "stdout-sorted" --file-is-lines \
		"=> Substituting \"one\" in file" \
		"=> Substituting \"three\" in file" \
		"=> Substituting \"two\" in file"
	assert_that "stderr" --file-is-empty
	assert_that "$exitcode" --equals 0

	test_case_end
fi


if test_case_begin "show diff"; then

	create_file_lines "file" "one" "two" "three"

	create_file "testcase.mk" <<EOF
SUBST_CLASSES+=		two
SUBST_STAGE.two=	pre-configure
SUBST_FILES.two=	file
SUBST_SED.two=		-e 's,two,II,'
SUBST_SHOW_DIFF.two=	yes

.include "prepare-subst.mk"
.include "mk/subst.mk"
EOF

	LC_ALL=C \
	run_bmake "testcase.mk" "pre-configure" \
		1> "$tmpdir/stdout" \
		2> "$tmpdir/stderr" \
	&& exitcode=0 || exitcode=$?

	awk '{ if (/^(---|\+\+\+) /) { print $1 " " $2 " (filtered timestamp)" } else { print $0 } }' \
	< "$tmpdir/stdout" > "$tmpdir/stdout-filtered"

	assert_that "file" --file-is-lines "one" "II" "three"
	assert_that "stdout-filtered" --file-is-lines \
		"=> Substituting \"two\" in file" \
		"--- file (filtered timestamp)" \
		"+++ file.subst.sav (filtered timestamp)" \
		"@@ -1,3 +1,3 @@" \
		" one" \
		"-two" \
		"+II" \
		" three"
	assert_that "stderr" --file-is-empty
	assert_that "$exitcode" --equals 0

	test_case_end
fi


if test_case_begin "global show diff"; then

	create_file_lines "file" "one" "two" "three"

	create_file "testcase.mk" <<EOF
SUBST_CLASSES+=		two
SUBST_STAGE.two=	pre-configure
SUBST_FILES.two=	file
SUBST_SED.two=		-e 's,two,II,'
SUBST_SHOW_DIFF=	yes

.include "prepare-subst.mk"
.include "mk/subst.mk"
EOF

	run_bmake "testcase.mk" "pre-configure" \
		1> "$tmpdir/stdout" \
		2> "$tmpdir/stderr" \
	&& exitcode=0 || exitcode=$?

	awk '{ if (/^(---|\+\+\+) /) { print $1 " " $2 " (filtered timestamp)" } else { print $0 } }' \
	< "$tmpdir/stdout" > "$tmpdir/stdout-filtered"

	assert_that "file" --file-is-lines "one" "II" "three"
	assert_that "stdout-filtered" --file-is-lines \
		"=> Substituting \"two\" in file" \
		"--- file (filtered timestamp)" \
		"+++ file.subst.sav (filtered timestamp)" \
		"@@ -1,3 +1,3 @@" \
		" one" \
		"-two" \
		"+II" \
		" three"
	assert_that "stderr" --file-is-empty
	assert_that "$exitcode" --equals 0

	test_case_end
fi


if test_case_begin "SUBST_VARS"; then

	create_file_lines "testcase.mk" \
		'SUBST_CLASSES+=	vars' \
		'SUBST_STAGE.vars=	pre-configure' \
		'SUBST_FILES.vars=	vars.txt' \
		'SUBST_VARS.vars=	PLAIN DQUOT SQUOT DELIM PRINTABLE' \
		'SUBST_VARS.vars+=	UNDEFINED' \
		'' \
		'PLAIN=		plain' \
		'DQUOT=		"double   quoted"' \
		'SQUOT=		'\''single   quoted'\''' \
		'DELIM=		hello,   world' \
		'PRINTABLE=	!"\#$$%&'\''()*+,-./09:;<=>?@AZ[\]^_`az{|}' \
		'#UNDEFINED=	# undefined' \
		'' \
		'.include "prepare-subst.mk"' \
		'.include "mk/subst.mk"'
	create_file_lines "vars.txt" \
		"@PLAIN@" \
		"@DQUOT@" \
		"@SQUOT@" \
		"@DELIM@" \
		"@PRINTABLE@" \
		"@UNDEFINED@"

	run_bmake "testcase.mk" "pre-configure" \
		1> "$tmpdir/stdout" \
		2> "$tmpdir/stderr" \
	&& exitcode=0 || exitcode=$?

	# The double quotes and single quotes are kept since the variables
	# are treated as simple string variables, not as lists of shell
	# words. In these string variables, the quotes are part of the value.
	assert_that "vars.txt" --file-is-lines \
		"plain" \
		"\"double   quoted\"" \
		"'single   quoted'" \
		"hello,   world" \
		'!"#$%&'\''()*+,-./09:;<=>?@AZ[\]^_`az{|}' \
		""
	assert_that "stdout" --file-is-lines \
		"=> Substituting \"vars\" in vars.txt"
	assert_that "stderr" --file-is-empty
	assert_that "$exitcode" --equals 0

	test_case_end
fi

if test_case_begin "SUBST_VARS with surrounding whitespace"; then

	# Ensure that leading and trailing whitespace is preserved
	# in the variable values.

	create_file_lines "testcase.mk" \
		'SUBST_CLASSES+=	vars' \
		'SUBST_STAGE.vars=	pre-configure' \
		'SUBST_FILES.vars=	vars.txt' \
		'SUBST_VARS.vars=	SPACE TAB NEWLINE' \
		'' \
		'SPACE=			${:U }between spaces${:U }' \
		'TAB=			${:U	}between tabs${:U	}' \
		'NEWLINE=		${.newline}between newlines${.newline}' \
		'' \
		'.include "prepare-subst.mk"' \
		'.include "mk/subst.mk"'
	create_file_lines "vars.txt" \
		"@SPACE@" \
		"@TAB@" \
		"@NEWLINE@"

	run_bmake "testcase.mk" "pre-configure" \
		1> "$tmpdir/stdout" \
		2> "$tmpdir/stderr" \
	&& exitcode=0 || exitcode=$?

	space=' '
	tab='	'
	newline='
'
	assert_that "vars.txt" --file-is-lines \
		"$space""between spaces""$space" \
		"$tab""between tabs""$tab" \
		"$newline""between newlines""$newline"
	assert_that "stdout" --file-is-lines \
		"=> Substituting \"vars\" in vars.txt"
	assert_that "stderr" --file-is-empty
	assert_that "$exitcode" --equals 0

	test_case_end
fi


if test_case_begin "SUBST_VARS with backslashes"; then

	create_file_lines "testcase.mk" \
		'SUBST_CLASSES+=	bs' \
		'SUBST_STAGE.bs=	pre-configure' \
		'SUBST_FILES.bs=	backslash.txt' \
		'SUBST_VARS.bs=		BACKSLASHES' \
		'' \
		'BACKSLASHES=	\" \, \\, \" \'\'' \0\000 \x40 \089 \a \$$' \
		'' \
		'.include "prepare-subst.mk"' \
		'.include "mk/subst.mk"'
	create_file_lines "backslash.txt" "@BACKSLASHES@"

	run_bmake "testcase.mk" "pre-configure" \
		1> "$tmpdir/stdout" \
		2> "$tmpdir/stderr" \
	&& exitcode=0 || exitcode=$?

	assert_that "backslash.txt" --file-is-lines \
		'\" \, \\, \" \'\'' \0\000 \x40 \089 \a \$'
	assert_that "stdout" --file-is-lines \
		"=> Substituting \"bs\" in backslash.txt"
	assert_that "stderr" --file-is-empty
	assert_that "$exitcode" --equals 0

	test_case_end
fi


if test_case_begin "SUBST_VARS for variables with regex characters"; then

	# Ensure that special regex characters like dots and parentheses
	# may appear in variable names and are properly escaped.

	# Variable names containing a dollar are not supported.
	# Bmake behaves very surprisingly when a $ is expanded inside a :C
	# modifier. Nobody needs this feature anyway, it was just an
	# experiment to see whether this would be theoretically possible.

	# Variable names ending with a backslash are not supported.
	# The backslash may only occur in the middle of the variable name.

	create_file_lines "testcase.mk" \
		'SUBST_CLASSES+=	vars' \
		'SUBST_STAGE.vars=	pre-configure' \
		'SUBST_FILES.vars=	vars.txt' \
		'SUBST_VARS.vars=	VAR...... VAR.abcde' \
		'SUBST_VARS.vars+=	VAR.() VAR.<> VAR.[]' \
		'SUBST_VARS.vars+=	VAR.$$x VAR.^ VAR.\x' \
		'' \
		'VAR......=	dots' \
		'VAR.abcde=	letters' \
		'VAR.()=	parentheses' \
		'VAR.<>=	angle brackets' \
		'VAR.[]=	square brackets' \
		'VAR.$$x=	dollar' \
		'VAR.^=		circumflex' \
		'VAR.\x=	backslash' \
		'' \
		'.include "prepare-subst.mk"' \
		'.include "mk/subst.mk"'
	create_file_lines "vars.txt" \
		"@VAR......@" \
		"@VAR.abcde@" \
		"@VAR.()@" \
		"@VAR.<>@" \
		"@VAR.[]@" \
		'@VAR.$x@' \
		'@VAR.^@' \
		'@VAR.\x@'

	run_bmake "testcase.mk" "pre-configure" \
		1> "$tmpdir/stdout" \
		2> "$tmpdir/stderr" \
	&& exitcode=0 || exitcode=$?

	assert_that "vars.txt" --file-is-lines \
		"dots" \
		"letters" \
		"parentheses" \
		"angle brackets" \
		"square brackets" \
		'@VAR.$x@' \
		'circumflex' \
		'backslash'
	assert_that "stdout" --file-is-lines \
		"=> Substituting \"vars\" in vars.txt"
	assert_that "stderr" --file-is-empty
	assert_that "$exitcode" --equals 0

	test_case_end
fi

if test_case_begin "pattern matches directory"; then

	# When a pattern matches a directory, that directory is silently
	# skipped.
	#
	# In this test case, the pattern also matches a regular file that
	# is actually modified. Therefore the pattern has an effect, and
	# there is no error message.

	create_file_lines "testcase.mk" \
		'SUBST_CLASSES+=	dir' \
		'SUBST_STAGE.dir=	pre-configure' \
		'SUBST_FILES.dir=	sub*' \
		'SUBST_VARS.dir=	VAR' \
		'SUBST_NOOP_OK.dir=	no' \
		'' \
		'VAR=			value' \
		'' \
		'.include "prepare-subst.mk"' \
		'.include "mk/subst.mk"'
	mkdir "$tmpdir/subdir"
	create_file_lines "subdir/subfile" \
		"@VAR@"
	create_file_lines "subst-file" \
		"@VAR@"

	run_bmake "testcase.mk" "pre-configure" \
		1> "$tmpdir/stdout" \
		2> "$tmpdir/stderr" \
	&& exitcode=0 || exitcode=$?

	assert_that "subst-file" --file-is-lines "value"
	assert_that "subdir/subfile" --file-is-lines "@VAR@" # unchanged
	assert_that "stdout" --file-is-lines \
		"=> Substituting \"dir\" in sub*"
	assert_that "stderr" --file-is-empty
	assert_that "$exitcode" --equals 0

	test_case_end
fi


if test_case_begin "pattern matches only directory"; then

	# When a pattern matches a directory, that directory is silently
	# skipped.

	create_file_lines "testcase.mk" \
		'SUBST_CLASSES+=	dir' \
		'SUBST_STAGE.dir=	pre-configure' \
		'SUBST_FILES.dir=	sub*' \
		'SUBST_VARS.dir=	VAR' \
		'SUBST_NOOP_OK.dir=	no' \
		'' \
		'VAR=			value' \
		'' \
		'.include "prepare-subst.mk"' \
		'.include "mk/subst.mk"'
	mkdir "$tmpdir/subdir"
	create_file_lines "subdir/subfile" \
		"@VAR@"

	run_bmake "testcase.mk" "pre-configure" \
		1> "$tmpdir/stdout" \
		2> "$tmpdir/stderr" \
	&& exitcode=0 || exitcode=$?

	assert_that "subdir/subfile" --file-is-lines "@VAR@" # unchanged
	assert_that "stdout" --file-is-lines \
		"=> Substituting \"dir\" in sub*" \
		'fail: [subst.mk:dir] The filename pattern "sub*" has no effect.' \
		"*** Error code 1" \
		"" \
		"Stop." \
		"$make: stopped in $PWD"
	assert_that "stderr" --file-is-empty
	assert_that "$exitcode" --equals 1

	test_case_end
fi


if test_case_begin "two filename patterns have no effect"; then

	# All patterns of SUBST_FILES should be applied before erroring out,
	# to give a complete picture of the situation.

	create_file_lines "testcase.mk" \
		'SUBST_CLASSES+=	id' \
		'SUBST_STAGE.id=	pre-configure' \
		'SUBST_FILES.id=	file1 file2' \
		'SUBST_VARS.id=		A B' \
		'SUBST_NOOP_OK.id=	no' \
		'A=			a-value' \
		'B=			b-value' \
		'' \
		'.include "prepare-subst.mk"' \
		'.include "mk/subst.mk"'
	create_file_lines "file1"	"nothing to replace"
	create_file_lines "file2"	"nothing to replace"

	run_bmake "testcase.mk" "pre-configure" 1> "$tmpdir/out" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "out" --file-is-lines \
		'=> Substituting "id" in file1 file2' \
		'warning: [subst.mk:id] Nothing changed in "file1".' \
		'warning: [subst.mk:id] Nothing changed in "file2".' \
		'fail: [subst.mk:id] The filename patterns "file1 file2" have no effect.' \
		'*** Error code 1' \
		'' \
		'Stop.' \
		"$make: stopped in $PWD"

	test_case_end
fi


if test_case_begin "empty SUBST_FILES"; then

	# An empty SUBST_FILES section is ok.
	# It may have been produced by a shell command like find(1).

	create_file_lines "testcase.mk" \
		'SUBST_CLASSES+=	id' \
		'SUBST_STAGE.id=	pre-configure' \
		'SUBST_FILES.id=	# none' \
		'SUBST_SED.id=		-e s,from,to,' \
		'SUBST_NOOP_OK.id=	no' \
		'' \
		'all:' \
		'	@printf "%s\n" ${PKG_FAIL_REASON:Uok}' \
		'' \
		'.include "prepare-subst.mk"' \
		'.include "mk/subst.mk"'

	run_bmake "testcase.mk" "pre-configure" "all" 1> "$tmpdir/out" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "out" --file-is-lines \
		'=> Substituting "id" in ' \
		'ok'

	test_case_end
fi


if test_case_begin "empty SUBST_SED"; then

	create_file_lines "testcase.mk" \
		'SUBST_CLASSES+=	id' \
		'SUBST_STAGE.id=	pre-configure' \
		'SUBST_FILES.id=	file' \
		'SUBST_SED.id=		# none' \
		'SUBST_NOOP_OK.id=	no' \
		'' \
		'all:' \
		'	@printf "%s\n" ${PKG_FAIL_REASON:Uok}' \
		'' \
		'.include "prepare-subst.mk"' \
		'.include "mk/subst.mk"'

	run_bmake "testcase.mk" "pre-configure" "all" 1> "$tmpdir/out" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "out" --file-is-lines \
		'=> Substituting "id" in file' \
		'warning: [subst.mk:id] Ignoring nonexistent file "file".' \
		'fail: [subst.mk:id] The filename pattern "file" has no effect.' \
		'*** Error code 1' \
		'' \
		'Stop.' \
		"$make: stopped in $PWD"

	test_case_end
fi


if test_case_begin "typo in SUBST_CLASSES"; then

	# Look closely. The SUBST_CLASSES line contains a typo.
	# subst.mk does not catch this, but pkglint does.

	create_file_lines "testcase.mk" \
		'SUBST_CLASSES=+	id' \
		'SUBST_STAGE.id=	pre-configure' \
		'SUBST_FILES.id=	file' \
		'SUBST_SED.id=		# none' \
		'SUBST_NOOP_OK.id=	no' \
		'' \
		'all:' \
		'	@printf "%s\n" ${PKG_FAIL_REASON:Uok}' \
		'' \
		'.include "prepare-subst.mk"' \
		'.include "mk/subst.mk"'

	run_bmake "testcase.mk" "pre-configure" "all" 1> "$tmpdir/out" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "out" --file-is-lines \
		'=> Substituting "id" in file' \
		'warning: [subst.mk:id] Ignoring nonexistent file "file".' \
		'fail: [subst.mk:id] The filename pattern "file" has no effect.' \
		'*** Error code 1' \
		'' \
		'Stop.' \
		"$make: stopped in $PWD"

	test_case_end
fi


if test_case_begin "executable bit is preserved"; then

	create_file_lines "testcase.mk" \
		'SUBST_CLASSES+=	id' \
		'SUBST_STAGE.id=	pre-configure' \
		'SUBST_FILES.id=	cmd data' \
		'SUBST_VARS.id=		VAR' \
		'VAR=			replaced' \
		'' \
		'.include "prepare-subst.mk"' \
		'.include "mk/subst.mk"'
	create_file_lines "cmd" \
		'@VAR@'
	create_file_lines "data" \
		'@VAR@'
	chmod +x "$tmpdir/cmd"

	run_bmake "testcase.mk" "pre-configure" 1> "$tmpdir/out" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "out" --file-is-lines \
		'=> Substituting "id" in cmd data'
	assert_that "cmd" --file-is-lines "replaced"
	assert_that "data" --file-is-lines "replaced"
	[ -x "$tmpdir/cmd" ] \
	|| assert_fail "cmd must still be executable"
	[ -x "$tmpdir/data" ] \
	&& assert_fail "data must not be executable"

	test_case_end
fi


if test_case_begin "unreadable file"; then

	create_file_lines "testcase.mk" \
		'SUBST_CLASSES+=	id' \
		'SUBST_STAGE.id=	pre-configure' \
		'SUBST_FILES.id=	unreadable-file' \
		'SUBST_SED.id=		-e s,before,after,' \
		'' \
		'.include "prepare-subst.mk"' \
		'.include "mk/subst.mk"'
	create_file_lines "unreadable-file" \
		'before'
	chmod 0000 "$tmpdir/unreadable-file"

	run_bmake "testcase.mk" "pre-configure" 1> "$tmpdir/out" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "out" --file-is-lines \
		'=> Substituting "id" in unreadable-file' \
		'sh: cannot open unreadable-file: permission denied' \
		'sh: cannot open unreadable-file: permission denied' \
		'*** Error code 1' \
		'' \
		'Stop.' \
		"$make: stopped in $PWD"

	test_case_end
fi


if test_case_begin "identity substitution implementation"; then

	assert_identity() {
		ai_expected="$1"; shift
		awk -f "$pkgsrcdir/mk/scripts/subst-identity.awk" -- "$@" \
		&& ai_actual="yes" || ai_actual="no"

		[ "$ai_actual" = "$ai_expected" ] \
		|| assert_fail "expected '%s', got '%s' for %s\n" "$ai_expected" "$ai_actual" "$*"
	}

	# If there is no SUBST_SED at all, this is not the situation
	# that is targeted by this test for identity substitution.
	assert_identity "no"	# no substitutions at all

	# Even though this is an identity substitution, it is missing
	# the -e option and thus does not follow the usual format.
	# Therefore it is considered just a normal substitution.
	assert_identity "no"	's,from,from,'

	# The following are typical identity substitutions.
	# It does not matter whether the g modifier is there or not.
	# Unknown modifiers are not allowed though.
	assert_identity "yes"	-e 's,from,from,'
	assert_identity "yes"	-e 's;from;from;'
	assert_identity "yes"	-e 's,from,from,g'
	assert_identity "no"	-e 's,from,from,gunknown'

	# The identity substitution may include characters other than
	# A-Za-z0-9, but no characters that have a special meaning in
	# basic regular expressions.
	assert_identity "yes"	-e 's,/dev/audio,/dev/audio,'
	assert_identity "yes"	-e 's!/dev/audio!/dev/audio!'

	# There may be several identity substitutions in the same
	# SUBST_SED.  As long as all these substitutions are identity
	# substitutions, they may be skipped.  As soon as there is one
	# other substitution, the whole SUBST_SED is treated as usual.
	assert_identity "yes"	-e 's;from;from;' -e 's!second!second!'
	assert_identity "no"	-e 's,changing,x,' -e 's,id,id,'
	assert_identity "no"	-e 's,id,id,' -e 's,changing,x,'

	# A demonstration of all ASCII characters that may appear in an
	# identity substitution.
	#
	# The # and $ are excluded since they are interpreted specially
	# in Makefiles and would thus be confusing to the human reader.
	#
	# The characters *.?[\]^ have a special meaning in the pattern of the
	# substitution.
	# The & has a special meaning in the replacement of the
	# substitution.
	specials='!"%'\''()+,-/:;<=>@_`{|}~'
	assert_identity "yes"	-e "sX${specials}X${specials}X"

	# Regular expression meta-characters may be escaped using a
	# backslash or be enclosed in square brackets.
	assert_identity 'yes'	-e 's,library\.so,library.so,g'
	assert_identity 'yes'	-e 's,library[.]so,library.so,g'
	assert_identity 'yes'	-e 's,[*],*,'
	assert_identity 'yes'	-e 's,[$],$,'

	# When this happens, it is probably a mistake.
	assert_identity	'no'	-e 's,,,'

	# Backslashes are not considered identity substitutions since
	# there might be tricky corner cases.
	assert_identity	'no'	-e 's,\\,\\,'

	# Back-references are not considered identity substitutions.
	assert_identity 'no'	-e 's,\1,\1,'

	# The & is interpreted specially in the replacement string.
	assert_identity 'no'	-e 's,&&&,&&&,'
	assert_identity 'no'	-e 's,\&,&,'
	assert_identity 'no'	-e 's,[&],&,'
	assert_identity 'no'	-e 's,&,\&,' # this would be an identity

	test_case_end
fi


if test_case_begin "identity substitution, found in file"; then

	# There are many situations in which a fixed text is replaced
	# with a dynamic value that may or may not be equal to the
	# original text.
	#
	# Typical examples are s|man|${PKGMANDIR}|, s|/usr/pkg|${PREFIX}|,
	# s|/dev/audio|${DEVOSSAUDIO}|.
	#
	# It is not an error if these substitutions result in a no-op,
	# provided that the text is actually found in the file.
	#
	# Alternatives for this special exception would be:
	#
	# 1. Mark these blocks as SUBST_NOOP_OK.  This would not detect
	# outdated definitions.  Since this detection is the main goal
	# of SUBST_NOOP_OK, this is out of the question.
	#
	# 2. Surround these blocks with a condition like ".if ${VAR} !=
	# fixed-value ... .endif".  This pattern only works if VAR is
	# definitely assigned, which often requires a corresponding
	# .include line, leading to code bloat.  It would also mean that
	# variables defined in bsd.pkg.mk could not be used in SUBST
	# blocks like these.

	create_file_lines "testcase.mk" \
		'SUBST_CLASSES+=	id' \
		'SUBST_FILES.id=	file' \
		'SUBST_SED.id=		-e s,before,before,' \
		'SUBST_SED.id+=		-e "s,before,before,"' \
		"SUBST_SED.id+=		-e 's,before,before,'" \
		'SUBST_NOOP_OK.id=	no' \
		'' \
		'.include "prepare-subst.mk"' \
		'.include "mk/subst.mk"'
	create_file_lines "file" \
		'before'

	run_bmake "testcase.mk" "subst-id" 1> "$tmpdir/out" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "out" --file-is-lines \
		'=> Substituting "id" in file'

	test_case_end
fi


if test_case_begin "identity substitution, not found in file"; then

	create_file_lines "testcase.mk" \
		'SUBST_CLASSES+=	id' \
		'SUBST_FILES.id=	file' \
		'SUBST_SED.id=		s,before,before,' \
		'SUBST_NOOP_OK.id=	no' \
		'' \
		'.include "prepare-subst.mk"' \
		'.include "mk/subst.mk"'
	create_file_lines "file" \
		'other'

	run_bmake "testcase.mk" "subst-id" 1> "$tmpdir/out" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "out" --file-is-lines \
		'=> Substituting "id" in file' \
		'warning: [subst.mk:id] Nothing changed in "file".' \
		'fail: [subst.mk:id] The filename pattern "file" has no effect.' \
		'*** Error code 1' \
		'' \
		'Stop.' \
		"$make: stopped in $PWD"

	test_case_end
fi


if test_case_begin "identity + effective substitution"; then

	create_file_lines "testcase.mk" \
		'SUBST_CLASSES+=	id' \
		'SUBST_FILES.id=	file' \
		'SUBST_SED.id=		-e s,no-op,no-op,g' \
		'SUBST_SED.id+=		-e s,from,to,' \
		'SUBST_NOOP_OK.id=	no' \
		'' \
		'.include "prepare-subst.mk"' \
		'.include "mk/subst.mk"'
	create_file_lines "file" \
		'from'

	run_bmake "testcase.mk" "subst-id" 1> "$tmpdir/out" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "out" --file-is-lines \
		'=> Substituting "id" in file'
	assert_that "file" --file-is-lines \
		'to'

	test_case_end
fi


if test_case_begin "identity + no-op substitution"; then

	# If there were only an identity substitution, it wouldn't be an
	# error.  But since there is a regular substitution as well,
	# that substitution is an unexpected no-op and is therefore
	# flagged as an error.

	create_file_lines "testcase.mk" \
		'SUBST_CLASSES+=	id' \
		'SUBST_FILES.id=	file' \
		'SUBST_SED.id=		-e s,no-op,no-op,g' \
		'SUBST_SED.id+=		-e s,from,to,' \
		'SUBST_NOOP_OK.id=	no' \
		'' \
		'.include "prepare-subst.mk"' \
		'.include "mk/subst.mk"'
	create_file_lines "file" \
		'other'

	run_bmake "testcase.mk" "subst-id" 1> "$tmpdir/out" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "out" --file-is-lines \
		'=> Substituting "id" in file' \
		'warning: [subst.mk:id] Nothing changed in "file".' \
		'fail: [subst.mk:id] The filename pattern "file" has no effect.' \
		'*** Error code 1' \
		'' \
		'Stop.' \
		"$make: stopped in $PWD"
	assert_that "file" --file-is-lines \
		'other'

	test_case_end
fi


if test_case_begin "SUBST_FILTER_CMD + SUBST_SED in NOOP_OK=no mode"; then

	# If SUBST_FILTER_CMD is defined for a SUBST class, the
	# corresponding SUBST_SED and SUBST_VARS are ignored. To avoid
	# redundant variable definitions, this case fails fast.

	create_file_lines "testcase.mk" \
		'SUBST_CLASSES+=	id' \
		'SUBST_FILES.id=	file' \
		'SUBST_FILTER_CMD.id=	tr -d "0-9"' \
		'SUBST_SED.id=		-e s,x,x,' \
		'SUBST_NOOP_OK.id=	no' \
		'' \
		'.include "prepare-subst.mk"' \
		'.include "mk/subst.mk"'
	create_file_lines "file" \
		'letters 123 letters'
	create_file_lines "main.mk" \
		"PKGSRCDIR=	$pkgsrcdir" \
		".PATH:		$mocked_pkgsrcdir" \
		".PATH:		$pkgsrcdir" \
		".include \"testcase.mk\"" \
		'' \
		'all: subst-id' \
		'	@printf '\''fail reason: %s\n'\'' ${PKG_FAIL_REASON} 1>&2'

	"$make" -f "$tmpdir/main.mk" "all" 1> "$tmpdir/out" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "out" --file-is-lines \
		'=> Substituting "id" in file' \
		'fail reason: [subst.mk:id] SUBST_FILTER_CMD and SUBST_SED/SUBST_VARS cannot be combined.'
	assert_that "file" --file-is-lines \
		'letters  letters'

	test_case_end
fi


if test_case_begin "effective SUBST_FILTER_CMD in NOOP_OK=no mode"; then

	create_file_lines "testcase.mk" \
		'SUBST_CLASSES+=	id' \
		'SUBST_FILES.id=	file' \
		'SUBST_FILTER_CMD.id=	tr -d "0-9"' \
		'SUBST_NOOP_OK.id=	no' \
		'' \
		'.include "prepare-subst.mk"' \
		'.include "mk/subst.mk"'
	create_file_lines "file" \
		'letters 123 letters'

	run_bmake "testcase.mk" "subst-id" 1> "$tmpdir/out" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "out" --file-is-lines \
		'=> Substituting "id" in file'
	assert_that "file" --file-is-lines \
		'letters  letters'

	test_case_end
fi


if test_case_begin "no-op SUBST_FILTER_CMD in NOOP_OK=no mode"; then

	create_file_lines "testcase.mk" \
		'SUBST_CLASSES+=	id' \
		'SUBST_FILES.id=	file' \
		'SUBST_FILTER_CMD.id=	tr -d "0-9"' \
		'SUBST_NOOP_OK.id=	no' \
		'' \
		'.include "prepare-subst.mk"' \
		'.include "mk/subst.mk"'
	create_file_lines "file" \
		'only letters'

	run_bmake "testcase.mk" "subst-id" 1> "$tmpdir/out" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "out" --file-is-lines \
		'=> Substituting "id" in file' \
		'warning: [subst.mk:id] Nothing changed in "file".' \
		'fail: [subst.mk:id] The filename pattern "file" has no effect.' \
		'*** Error code 1' \
		'' \
		'Stop.' \
		"$make: stopped in $PWD"

	assert_that "file" --file-is-lines \
		'only letters'

	test_case_end
fi


if test_case_begin "backtick in SUBST_SED"; then

	create_file_lines "testcase.mk" \
		'SUBST_CLASSES+=	id' \
		'SUBST_FILES.id=	file' \
		"SUBST_SED.id=		-e 's,\"\\\\\`,\"\\\\\`,'" \
		'' \
		'.include "prepare-subst.mk"' \
		'.include "mk/subst.mk"'
	create_file_lines "file" \
		'from`'

	run_bmake "testcase.mk" "subst-id" 1> "$tmpdir/out" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "out" --file-is-lines \
		'=> Substituting "id" in file' \
		'info: [subst.mk:id] Nothing changed in "file".'

	test_case_end
fi


if test_case_begin "multiple sed commands with semicolon"; then

	# From PR pkg/55226:
	#  ===> Configuring for perl-5.30.2
	# sh: 1: Syntax error: Word "/d"p" unexpected (expecting ")")

	create_file_lines "testcase.mk" \
		'SUBST_CLASSES+=	id' \
		'SUBST_FILES.id=	file' \
		'SUBST_SED.id=		-e "s/755/755/g;/umask(/d"' \
		'SUBST_NOOP_OK.id=	no' \
		'' \
		'.include "prepare-subst.mk"' \
		'.include "mk/subst.mk"'
	create_file_lines "file" \
		'$mode = 755;'

	run_bmake "testcase.mk" "subst-id" 1> "$tmpdir/out" 2>&1 \
	&& exitcode=0 || exitcode=$?

	assert_that "out" --file-is-lines \
		'=> Substituting "id" in file' \
		'warning: [subst.mk:id] Nothing changed in "file".' \
		'fail: [subst.mk:id] The filename pattern "file" has no effect.' \
		'*** Error code 1' \
		'' \
		'Stop.' \
		"$make: stopped in $PWD"

	test_case_end
fi
