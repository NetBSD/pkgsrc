# $NetBSD: plist-macros.awk,v 1.1 2007/10/31 21:09:03 rillig Exp $

BEGIN {
	IMAKE_MANINSTALL = getenv_or_die("IMAKE_MANINSTALL")
}

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
