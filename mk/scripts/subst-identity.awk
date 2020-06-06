#! /usr/bin/awk -f
# $NetBSD: subst-identity.awk,v 1.5 2020/06/06 13:17:34 rillig Exp $
#
# Tests whether a sed(1) command line contains an identity substitution
# like s,id,id,.  When used in a SUBST block, these commands may leave a
# file unmodified, which is ok since such an identity substitution
# typically looks like s,/var,${VARBASE},.
#
# See SUBST_NOOP_OK and regress/infra-unittests/subst.sh.
#

BEGIN {
	false = 0;
	true = 1;
}

# Returns the first character of the given regular expression,
# if it is a single-character regular expression.
function identity_char(s, sep, i) {
	if (s ~ /^[\t -~]/ && s !~ /^[$&*.\[\\\]^]/)
		return substr(s, 1, 1);
	if (s ~ /^\\[$*.\[\]^]/)
		return substr(s, 2, 1) "x";
	if (s ~ /^\[[$*.]\]/)
		return substr(s, 2, 1) "xx";
	if (substr(s, 1, 1) == "$" && substr(s, 2, 1) != sep)
		return substr(s, 1, 1);
	if (substr(s, 1, 1) == "^" && i > 3)
		return substr(s, 1, 1);
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
		ch = identity_char(substr(s, i), sep, i);
		if (ch == "")
			break;
		pat_to = pat_to substr(ch, 1, 1);
		i += length(ch);
	}

	if (pat_to == "")
		return 0; # only for GNU Awk 5.0.1 in -Lfatal mode
	pat_from = substr(s, 3, i - 3);

	subst = "s" sep pat_from sep pat_to sep;
	return s == subst || s == subst "g" || s == subst "1";
}

function contains_identity_subst(   i) {
	for (i = 1; i + 1 < ARGC; i += 2)
		if (ARGV[i] == "-e" && is_identity_subst(ARGV[i + 1]))
			return true;
	return false;
}

BEGIN {
	exit(contains_identity_subst() ? 0 : 1);
}
