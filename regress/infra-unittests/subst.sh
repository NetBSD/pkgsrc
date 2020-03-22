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
		'warning: [subst.mk:class] Nothing changed in ./single.' \
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
		'info: [subst.mk:class] Ignoring non-existent file "./nonexistent".'
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
		'info: [subst.mk:class] Ignoring non-existent file "./*not-found*".'
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
		'info: [subst.mk:class] Ignoring non-existent file "./does".' \
		'info: [subst.mk:class] Ignoring non-existent file "./not".' \
		'info: [subst.mk:class] Ignoring non-existent file "./exist".'
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

	test_file "testcase.mk" "pre-configure" \
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
	test_file "testcase.mk" "pre-configure" \
		1> "$tmpdir/stdout" \
		2> "$tmpdir/stderr" \
	&& exitcode=0 || exitcode=$?

	awk '{ if (/^... \.\/.*/) { print $1 " " $2 " (filtered timestamp)" } else { print $0 } }' \
	< "$tmpdir/stdout" > "$tmpdir/stdout-filtered"

	assert_that "file" --file-is-lines "one" "II" "three"
	assert_that "stdout-filtered" --file-is-lines \
		"=> Substituting \"two\" in file" \
		"--- ./file (filtered timestamp)" \
		"+++ ./file.subst.sav (filtered timestamp)" \
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

	test_file "testcase.mk" "pre-configure" \
		1> "$tmpdir/stdout" \
		2> "$tmpdir/stderr" \
	&& exitcode=0 || exitcode=$?

	awk '{ if (/^... \.\/.*/) { print $1 " " $2 " (filtered timestamp)" } else { print $0 } }' \
	< "$tmpdir/stdout" > "$tmpdir/stdout-filtered"

	assert_that "file" --file-is-lines "one" "II" "three"
	assert_that "stdout-filtered" --file-is-lines \
		"=> Substituting \"two\" in file" \
		"--- ./file (filtered timestamp)" \
		"+++ ./file.subst.sav (filtered timestamp)" \
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

	test_file "testcase.mk" "pre-configure" \
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

	test_file "testcase.mk" "pre-configure" \
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

	test_file "testcase.mk" "pre-configure" \
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

	create_file_lines "testcase.mk" \
		'SUBST_CLASSES+=	vars' \
		'SUBST_STAGE.vars=	pre-configure' \
		'SUBST_FILES.vars=	vars.txt' \
		'SUBST_VARS.vars=	VAR...... VAR.abcde VAR.() VAR.<>' \
		'' \
		'VAR......=	dots' \
		'VAR.abcde=	letters' \
		'VAR.()=	parentheses' \
		'VAR.<>=	angle brackets' \
		'VAR.[]=	square brackets' \
		'' \
		'.include "prepare-subst.mk"' \
		'.include "mk/subst.mk"'
	create_file_lines "vars.txt" \
		"@VAR......@" \
		"@VAR.abcde@" \
		"@VAR.()@" \
		"@VAR.<>@" \
		"@VAR.[]@"

	test_file "testcase.mk" "pre-configure" \
		1> "$tmpdir/stdout" \
		2> "$tmpdir/stderr" \
	&& exitcode=0 || exitcode=$?

	# TODO: Why are the angle brackets replaced, but not the parentheses
	# and square brackets?
	assert_that "vars.txt" --file-is-lines \
		"dots" \
		"letters" \
		"@VAR.()@" \
		"angle brackets" \
		"@VAR.[]@"
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

	test_file "testcase.mk" "pre-configure" \
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

	test_file "testcase.mk" "pre-configure" \
		1> "$tmpdir/stdout" \
		2> "$tmpdir/stderr" \
	&& exitcode=0 || exitcode=$?

	assert_that "subdir/subfile" --file-is-lines "@VAR@" # unchanged
	assert_that "stdout" --file-is-lines \
		"=> Substituting \"dir\" in sub*" \
		"fail: [subst.mk:dir] The pattern sub* has no effect." \
		"*** Error code 1" \
		"" \
		"Stop." \
		"$make: stopped in $PWD"
	assert_that "stderr" --file-is-empty
	assert_that "$exitcode" --equals 1

	test_case_end
fi
