# $NetBSD: version.mk,v 1.3 2010/11/23 21:22:11 asau Exp $
###
.if !defined(GAMBC_VERSION_MK)
GAMBC_VERSION_MK=	# empty
###
### The package version sets the distribution version.
###
GAMBC_VERSION=		4.6.0
GAMBC_DIST_VERSION=	${GAMBC_VERSION:C|^.*|v&|:S|.|_|g}
.endif
