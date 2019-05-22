#! /bin/sh
# $NetBSD: logging-test.sh,v 1.7 2019/05/22 20:47:05 rillig Exp $

# Up to March 2019, the command logging for the wrapped tools didn't properly
# quote the command line arguments. This meant the logging did not reflect
# the actual tool command line.

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
[*] WRKDIR/.tools/bin/echo begin '*' '*' '*' end
<.> echo  begin '*' '*' '*' end
[*] WRKDIR/.tools/bin/echo dquot '"' end
<.> echo  dquot '"' end
[*] WRKDIR/.tools/bin/echo squot ''\''' end
<.> echo  squot ''\''' end
[*] WRKDIR/.tools/bin/echo five '\\\\\' end
<.> echo  five '\\\\\' end
EOF
}

test_case "TOOLS_PATH with TOOLS_ARGS"
{
	# The mkdir tool always gets the -p option.

	run_tool mkdir "directory with spaces"

	# The TOOLS_ARGS are already quoted, therefore they all look
	# different in the log. The actual arguments, on the other hand,
	# all look the same.
	assert_log <<'EOF'
[*] WRKDIR/.tools/bin/mkdir 'directory with spaces'
<.> BINDIR/mkdir -p 'directory with spaces'
EOF
}

test_case "TOOLS_PATH with TOOLS_ARGS containing double quotes"
{
	run_tool path-args-dquot "and" \" "\"" '"'

	assert_log <<'EOF'
[*] WRKDIR/.tools/bin/path-args-dquot and '"' '"' '"'
<.> echo \" "\"" '"' and '"' '"' '"'
EOF
}

test_case "TOOLS_PATH with TOOLS_ARGS containing special characters"
{
	run_tool path-args "and" " \"'\\\$" "*"

	assert_log <<'EOF'
[*] WRKDIR/.tools/bin/path-args and ' "'\''\$' '*'
<.> echo " \"'\\$" "*" and ' "'\''\$' '*'
EOF
}

test_case "TOOLS_SCRIPT with dquot"
{
	run_tool script-dquot

	assert_log <<'EOF'
[*] WRKDIR/.tools/bin/script-dquot
<.> set args; shift; echo "hello; world"
EOF
}

test_case "TOOLS_SCRIPT with backslashes"
{
	run_tool script-backslash

	assert_log <<'EOF'
[*] WRKDIR/.tools/bin/script-backslash
<.> set args; shift; echo hello\;\ world
EOF
}

test_case "TOOLS_SCRIPT with complicated replacement"
{
	run_tool for-loop "one" "two" "three"

	# The actual command is written to the log in a form as close as
	# possible to replay it. Since the command may do anything with
	# its arguments, it's the safest way to set them first and then
	# just log the command verbatim.
	#
	# In this example, the $0 becomes unrealistic when the command
	# is replayed. In practice $0 is seldom used.
	assert_log <<'EOF'
[*] WRKDIR/.tools/bin/for-loop one two three
<.> set args one two three; shift; printf '%s' "$0";  for arg in "$@"; do  printf ' <%s>' "$arg";  done;  printf '\n'
EOF
}

test_case "TOOLS_SCRIPT with actual arguments containing quotes"
{
	run_tool for-loop \
		-DSD='"a b"' \
		-DSS=''\''a b'\''' \
		-DDD="\"a b\"" \
		-DB=\"a\ b\"

	assert_log <<'EOF'
[*] WRKDIR/.tools/bin/for-loop -DSD='"a b"' -DSS=''\''a b'\''' -DDD='"a b"' -DB='"a b"'
<.> set args -DSD='"a b"' -DSS=''\''a b'\''' -DDD='"a b"' -DB='"a b"'; shift; printf '%s' "$0";  for arg in "$@"; do  printf ' <%s>' "$arg";  done;  printf '\n'
EOF
}
