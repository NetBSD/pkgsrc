# $NetBSD: Makefile,v 1.6 2001/12/20 22:31:09 jlam Exp $

PKGNAME=	ghostscript-${GS_VERS}
PKGREVISION=	1
COMMENT=	Aladdin Postscript interpreter

CONFLICTS=	ghostscript{,-x11,-nox11}-[0-9]*

USE_BUILDLINK_ONLY=	YES

.include "../../print/ghostscript-nox11/Makefile.common"

MAKEFRAGS+=		${FILESDIR}/devs.x11
GS_DISPLAY_DEVICE=	x11.dev
XLIBS=			Xt SM ICE Xext X11

.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"

# arm32 compiler has an optimizer problem
.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "arm32"
CFLAGS+=	-O0
.endif
