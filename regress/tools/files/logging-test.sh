#! /bin/sh
# $NetBSD: logging-test.sh,v 1.3 2019/03/22 22:41:06 rillig Exp $

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

TOOLS_WRAPPER_LOG="$tools_log"
export TOOLS_WRAPPER_LOG

# Forcibly call the tools from the tools directory, not the shell builtins.
# The echo tool is a wrapped tool without additional arguments.
# The mkdir tool is a wrapped tool that always gets the -p option.
(exec echo "begin" "*" "*" "*" "end")
(exec echo "dquot" "\"" "end")
(exec echo "squot" "'" "end")
(exec echo "five" '\\\\\' "end")
(exec mkdir "directory with spaces")
(exec script-dquot)
(exec script-backslash)

unset TOOLS_WRAPPER_LOG

# usage: assert_file_equals $filename <<EOF ... EOF
assert_file_equals() {
	actual=`cat "$1"`
	expected=`cat`
	assert_equal "$1" "$expected" "$actual"
}

# Replace the variable parts from the output with placeholders.
sed < "$tools_log" > "$nopath_log"		\
	-e 's,/.*/\.tools/,WRKDIR/.tools/,'	\
	-e 's,^<.> /[^ ]*/,<.> BINDIR/,'

# The double space in the "echo  begin" below is because the echo command
# doesn't get any additional arguments by the tool wrapper (TOOLS_ARGS.echo).
#
# The log doesn't show delimiters for the arguments, which makes the call to
# mkdir ambiguous. Doing proper shell quoting would require code similar to
# shquote from mk/scripts/shell-lib. This may make the tools wrapper slower.
assert_file_equals "$nopath_log" <<'EOF'
[*] WRKDIR/.tools/bin/echo begin * * * end
<.> echo  begin * * * end
[*] WRKDIR/.tools/bin/echo dquot " end
<.> echo  dquot " end
[*] WRKDIR/.tools/bin/echo squot ' end
<.> echo  squot ' end
[*] WRKDIR/.tools/bin/echo five \\\\\ end
<.> echo  five \\\\\ end
[*] WRKDIR/.tools/bin/mkdir directory with spaces
<.> BINDIR/mkdir -p directory with spaces
[*] WRKDIR/.tools/bin/script-dquot 
[*] WRKDIR/.tools/bin/world 
<.> echo oops
oops
[*] WRKDIR/.tools/bin/script-backslash 
<.> echo hello\;\ world
EOF

# FIXME: The tool wrapper log must contain [*] and <.> equally often.
# Explanation:
# In WRKDIR/.tools/bin/script-dquot, the shell quoting is obviously wrong.
# This results in "hello" being echoed to stdout instead of the log file.
# This also results in the "hello" tool to be run.
# The output of that tool is appended to the log file, as can be seen in
# the tool wrapper script.
