# $NetBSD: Makefile,v 1.6 2002/03/16 23:34:37 wiz Exp $

PKGNAME=	ghostscript-nox11-${GS_VERS}
PKGREVISION=	4
COMMENT=	Aladdin Postscript interpreter without X11 drivers

CONFLICTS=	ghostscript{,-x11}-[0-9]*

USE_BUILDLINK_ONLY=	YES

.include "../../print/ghostscript-nox11/Makefile.common"
.include "../../mk/bsd.pkg.mk"

# arm32 compiler has an optimizer problem
.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "arm32"
CFLAGS+=	-O0
.endif
