# $NetBSD: plist-macros.awk,v 1.2 2008/01/05 17:03:04 rillig Exp $

BEGIN {
	IMAKE_MANINSTALL = getenv_or_die("IMAKE_MANINSTALL")
}

# XXX: Don't use this macro, since it is not yet supported.
#
# @imake-man dir basename extension
#
# Creates up to two PLIST entries for man pages of imake-style programs.
#
/^@imake-man/ {
	if (IMAKE_MANINSTALL ~ /catinstall/) {
		n = split($2, components, "/")
		sub("man", "cat", components[n])
		print join(components, 1, n, "/") "/" $3 ".0"
	}
	if (IMAKE_MANINSTALL ~ /maninstall/) {
		n = split($2, components, "/")
		sub("cat", "man", components[n])
		print join(components, 1, n, "/") "/" $3 "." $4
	}
	next;
}

1 {
	print;
}
