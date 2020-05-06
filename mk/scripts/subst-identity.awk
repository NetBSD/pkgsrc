#! /usr/bin/awk -f
# $NetBSD: subst-identity.awk,v 1.2 2020/05/06 06:14:56 rillig Exp $
#
# Tests whether a sed(1) command line consists of only identity substitutions
# like s,id,id,.
#
# See SUBST_NOOP_OK and regress/infra-unittests/subst.sh.
#

# Returns the first character of the given regular expression,
# if it is a single-character regular expression.
function identity_char(s) {
	if (s ~ /^[\t -~]/ && s !~ /^[$&*.\[\\\]^]/)
		return substr(s, 1, 1);
	if (s ~ /^\\[$*.\[\]^]/)
		return substr(s, 2, 1) "x";
	if (s ~ /^\[[$*.]\]/)
		return substr(s, 2, 1) "xx";
	return "";
}

# Tests whether a single "s,from,to," is an identity substitution.
function is_identity_subst(s,   len, i, sep, pat_from, pat_to, ch, subst) {
	len = length(s);
	if (len < 6 || substr(s, 1, 1) != "s")
		return 0;

	sep = substr(s, 2, 1);
	i = 3;
	pat_to = "";
	while (i < len && substr(s, i, 1) != sep) {
		ch = identity_char(substr(s, i));
		if (ch == "")
			break;
		pat_to = pat_to substr(ch, 1, 1);
		i += length(ch);
	}

	if (pat_to == "")
		return 0; # only for GNU Awk 5.0.1 in -Lfatal mode
	pat_from = substr(s, 3, i - 3);

	subst = "s" sep pat_from sep pat_to sep;
	return s == subst || s == subst "g";
}

function main(   i) {
	for (i = 1; i + 1 < ARGC; i += 2)
		if (ARGV[i] != "-e" || !is_identity_subst(ARGV[i + 1]))
			return 0;
	return i == ARGC && ARGC > 1;
}

BEGIN {
	exit(main() ? 0 : 1);
}
