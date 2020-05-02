#! /bin/sh
set -eu

. "${PKGSRCDIR}/mk/tools/shquote.sh"

# test_shquote $in becomes $out
test_shquote() {
	shquote "$1"
	[ "x$shquoted" = "x$3" ] && return
	printf 'input:    %s\nexpected: %s\nactual:   %s\n' "$1" "$3" "$shquoted" 1>&2
	exit 1
}

tools_wrapper_sed=${SED:-/usr/bin/sed}

test_shquote '' becomes "''"

test_shquote ' ' becomes "' '"
test_shquote '!' becomes '!'
test_shquote '"' becomes "'\"'"
test_shquote '#' becomes "'#'"
test_shquote '$' becomes "'$'"
test_shquote '%' becomes '%'
test_shquote '&' becomes "'&'"
test_shquote \' becomes "''\\'''"
test_shquote '(' becomes "'('"
test_shquote ')' becomes "')'"
test_shquote '*' becomes "'*'"
test_shquote '+,-./0123456789:' becomes '+,-./0123456789:'
test_shquote ';' becomes "';'"
test_shquote '<' becomes "'<'"
test_shquote '=' becomes '='
test_shquote '>' becomes "'>'"
test_shquote '?' becomes "'?'"
test_shquote '@ABCDEFGHIJKLMNOPQRSTUVWXYZ' becomes '@ABCDEFGHIJKLMNOPQRSTUVWXYZ'
test_shquote '[' becomes "'['"
test_shquote '\' becomes "'\\'"
test_shquote ']' becomes "']'"
test_shquote '^' becomes "'^'"
test_shquote '_' becomes '_'
test_shquote '`' becomes "'\`'"
test_shquote 'abcdefghijklmnopqrstuvwxyz' becomes 'abcdefghijklmnopqrstuvwxyz'
test_shquote '{' becomes "'{'"
test_shquote '|' becomes "'|'"
test_shquote '}' becomes "'}'"
test_shquote '~' becomes "'~'"

test_shquote 'a b' becomes "'a b'"
test_shquote 'a   b' becomes "'a   b'"
test_shquote '	' becomes "'	'"
test_shquote '-e asdf' becomes "'-e asdf'"
test_shquote '-n' becomes '-n'
test_shquote '\\\\\\\\' becomes \''\\\\\\\\'\'
test_shquote \"\$\'\;\<\\\` becomes \'\"\$\'\\\'\'\;\<\\\`\'

# Move the single quote to the right of the equals sign, if possible.
test_shquote '-DMACRO="value"' becomes "-DMACRO='\"value\"'"
test_shquote '--prefix="/usr/local"' becomes "--prefix='\"/usr/local\"'"
test_shquote '-assignment=first=second=""' becomes "-assignment='first=second=\"\"'"
test_shquote '-assignment=first=second' becomes '-assignment=first=second'

# If the left-hand side needs to be quoted as well, quote the whole string.
test_shquote '"left"="right"' becomes "'\"left\"=\"right\"'"
