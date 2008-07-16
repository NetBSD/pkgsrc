# $NetBSD: version.mk,v 1.2 2008/07/16 07:14:36 bjs Exp $
###
.if !defined(GAMBC_VERSION_MK)
GAMBC_VERSION_MK=	# empty
###
### The package version sets the distribution version.
###
GAMBC_VERSION=		4.2.8
GAMBC_DIST_VERSION=	${GAMBC_VERSION:C|^.*|v&|:S|.|_|g}
.endif
