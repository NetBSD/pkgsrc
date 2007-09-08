# $NetBSD: Makefile,v 1.31 2007/09/08 21:57:58 jlam Exp $

USE_FEATURES=	nbcompat

.include "Makefile.common"

CATEGORIES=	archivers
PKGREVISION=	1

# pax installs "tar" and "cpio"
.if defined(GNU_PROGRAM_PREFIX) && ${GNU_PROGRAM_PREFIX} == ""
CONFLICTS+=	gcpio-[0-9]*
.endif
.if defined(GTAR_PROGRAM_PREFIX) && ${GTAR_PROGRAM_PREFIX} == ""
CONFLICTS+=	gtar-base-[0-9]*
.endif

.include "../../mk/bsd.pkg.mk"
