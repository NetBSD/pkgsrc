# $NetBSD: Makefile,v 1.33 2007/11/11 16:51:27 joerg Exp $

USE_FEATURES=	nbcompat

.include "Makefile.common"

CATEGORIES=	archivers
PKGREVISION=	3

# pax installs "tar" and "cpio"
.if defined(GNU_PROGRAM_PREFIX) && ${GNU_PROGRAM_PREFIX} == ""
CONFLICTS+=	gcpio-[0-9]*
.endif
.if defined(GTAR_PROGRAM_PREFIX) && ${GTAR_PROGRAM_PREFIX} == ""
CONFLICTS+=	gtar-base-[0-9]*
.endif

.include "../../mk/bsd.pkg.mk"
