#! /bin/sh
# $NetBSD: logging-test.sh,v 1.4 2019/03/23 22:59:11 rillig Exp $

# Up to March 2019, the command logging for the wrapped tools didn't properly
# quote the command line arguments. This meant the logging did not reflect
# the actual tool command line.
#
# As of March 2019 the logging has been fixed for tool wrappers that consist
# only of a TOOLS_PATH.${tool} and TOOLS_ARGS.${tool}. For tools with custom
# TOOLS_SCRIPTS it's much more difficult to do the quoting properly. See the
# wrapper for makeinfo for a good example.

set -eu

mydir=`dirname "$0"`
. "${mydir}/tests.subr"

tools_log="./tools.log"
nopath_log="./nopath.log"

rm -f "$tools_log" "$nopath_log"

test_case() {
	test_name="$1"
}

# usage: run_tool $tool $args...
run_tool() {
	TOOLS_WRAPPER_LOG="$tools_log"
	export TOOLS_WRAPPER_LOG

	# The exec makes sure that the tool from the tools directory is
	# called, even for shell builtins.
	(exec "$@")

	unset TOOLS_WRAPPER_LOG

}

# usage: assert_log <<EOF ... EOF
assert_log() {
	# Replace the variable parts from the output with placeholders.
	sed < "$tools_log" > "$nopath_log"		\
		-e 's,/.*/\.tools/,WRKDIR/.tools/,'	\
		-e 's,^<.> /[^ ]*/,<.> BINDIR/,'

	actual=`cat "$nopath_log"`
	expected=`cat`
	assert_equal "$test_name" "$expected" "$actual" || exit $?

	rm -f "$tools_log" "$nopath_log"
	unset test_name
}

test_case "TOOLS_PATH without TOOLS_ARGS"
{
	# The "*" ensure that there is no accidental file expansion.
	run_tool echo "begin" "*" "*" "*" "end"
	run_tool echo "dquot" "\"" "end"
	run_tool echo "squot" "'" "end"
	run_tool echo "five" '\\\\\' "end"

	# In the <.> lines there are 2 spaces between echo and its first
	# argument. This is because the echo command doesn't get any
	# additional arguments by the tool wrapper (TOOLS_ARGS.echo).

	assert_log <<'EOF'
[*] WRKDIR/.tools/bin/echo begin * * * end
<.> echo  begin * * * end
[*] WRKDIR/.tools/bin/echo dquot " end
<.> echo  dquot " end
[*] WRKDIR/.tools/bin/echo squot ' end
<.> echo  squot ' end
[*] WRKDIR/.tools/bin/echo five \\\\\ end
<.> echo  five \\\\\ end
EOF
}

test_case "TOOLS_PATH with TOOLS_ARGS"
{
	# The mkdir tool always gets the -p option.

	run_tool mkdir "directory with spaces"

	# The log doesn't show delimiters for the arguments, which makes
	# the call to mkdir ambiguous. Doing proper shell quoting would
	# require code similar to shquote from mk/scripts/shell-lib.
	# This may make the tools wrapper slower.
	assert_log <<'EOF'
[*] WRKDIR/.tools/bin/mkdir directory with spaces
<.> BINDIR/mkdir -p directory with spaces
EOF
}

test_case "TOOLS_SCRIPT with dquot"
{
	run_tool script-dquot

	# The following log output contains a trailing whitespace. This
	# is because the tool didn't get any actual arguments.
	#
	# FIXME: the "echo oops" occurs because the script is not
	# properly quoted during logging.
	assert_log <<'EOF'
[*] WRKDIR/.tools/bin/script-dquot 
[*] WRKDIR/.tools/bin/world 
<.> echo oops
oops
EOF
}

test_case "TOOLS_SCRIPT with backslashes"
{
	run_tool script-backslash

	# The following log output contains a trailing whitespace. This
	# is because the tool didn't get any actual arguments.
	assert_log <<'EOF'
[*] WRKDIR/.tools/bin/script-backslash 
<.> echo hello\;\ world
EOF
}

test_case "TOOLS_SCRIPT with complicated replacement"
{
	run_tool for-loop "one" "two" "three"

	# TODO: Add proper quoting for the printf argument inside the loop.
	assert_log <<'EOF'
[*] WRKDIR/.tools/bin/for-loop one two three
<.> printf '%s' WRKDIR/.tools/bin/for-loop;  for arg in one two three; do  printf ' <%s>' ;  done;  printf '\n'
EOF
}

test_case "TOOLS_SCRIPT with actual arguments containing quotes"
{
	run_tool for-loop \
		-DSD='"a b"' \
		-DSS=''\''a b'\''' \
		-DDD="\"a b\"" \
		-DB=\"a\ b\"

	# TODO: Add proper quoting for the arguments.
	assert_log <<'EOF'
[*] WRKDIR/.tools/bin/for-loop -DSD="a b" -DSS='a b' -DDD="a b" -DB="a b"
<.> printf '%s' WRKDIR/.tools/bin/for-loop;  for arg in -DSD="a b" -DSS='a b' -DDD="a b" -DB="a b"; do  printf ' <%s>' ;  done;  printf '\n'
EOF
}
