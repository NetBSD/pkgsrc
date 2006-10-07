# $NetBSD: Makefile,v 1.29 2006/10/07 16:52:19 reed Exp $

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

.include "../../pkgtools/libnbcompat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
