# $NetBSD: version.mk,v 1.6 2024/04/11 15:19:11 ktnb Exp $
###
.if !defined(GAMBC_VERSION_MK)
GAMBC_VERSION_MK=	# empty
###
### The package version sets the distribution version.
###
GAMBC_VERSION=		4.9.5
GAMBC_DIST_VERSION=	${GAMBC_VERSION:C|^.*|v&|:S|.|_|g}
.endif
