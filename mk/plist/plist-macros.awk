# $NetBSD: plist-macros.awk,v 1.3 2024/03/29 00:16:25 js Exp $

BEGIN {
	IMAKE_MANINSTALL = ENVIRON["IMAKE_MANINSTALL"]
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
