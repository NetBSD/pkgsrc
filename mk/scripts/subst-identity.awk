#! /usr/bin/awk -f
# $NetBSD: subst-identity.awk,v 1.1 2020/04/29 18:33:57 rillig Exp $
#
# Tests whether a sed(1) command line consists of only identity substitutions
# like s,id,id,.
#
# See SUBST_NOOP_OK and regress/infra-unittests/subst.sh.
#

function is_safe_char(ch) {
	return ch ~ /[\t -~]/ && ch !~ /[$&*.\[\\\]^]/;
}

function is_identity_subst(s,   len, i, sep, pat) {
	len = length(s);
	if (len < 6 || substr(s, 1, 1) != "s")
		return 0;

	sep = substr(s, 2, 1);
	i = 3;
	while (i < len && substr(s, i, 1) != sep && is_safe_char(substr(s, i, 1)))
		i++;
	pat = substr(s, 3, i - 3);

	return (s == "s" sep pat sep pat sep ||
		s == "s" sep pat sep pat sep "g");
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
