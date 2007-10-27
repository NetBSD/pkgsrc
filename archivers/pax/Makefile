# $NetBSD: Makefile,v 1.32 2007/10/27 11:19:04 grant Exp $

USE_FEATURES=	nbcompat

.include "Makefile.common"

CATEGORIES=	archivers
PKGREVISION=	2

# pax installs "tar" and "cpio"
.if defined(GNU_PROGRAM_PREFIX) && ${GNU_PROGRAM_PREFIX} == ""
CONFLICTS+=	gcpio-[0-9]*
.endif
.if defined(GTAR_PROGRAM_PREFIX) && ${GTAR_PROGRAM_PREFIX} == ""
CONFLICTS+=	gtar-base-[0-9]*
.endif

.include "../../mk/bsd.pkg.mk"
