# $NetBSD: Makefile,v 1.30 2007/09/06 21:51:53 jlam Exp $

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

.include "../../pkgtools/libnbcompat/inplace.mk"
.include "../../mk/bsd.pkg.mk"
