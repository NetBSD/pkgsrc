# $NetBSD: Makefile,v 1.9.2.2 2002/06/21 23:05:38 jlam Exp $

PKGNAME=	ghostscript-${GS_VERS}
PKGREVISION=	4
COMMENT=	Aladdin Postscript interpreter

CONFLICTS=	ghostscript{,-x11,-nox11}-[0-9]*

USE_BUILDLINK2=	YES
USE_X11=	YES

.include "../../print/ghostscript-nox11/Makefile.common"

MAKEFRAGS+=		${FILESDIR}/devs.x11
GS_DISPLAY_DEVICE=	x11.dev
XLIBS=			Xt SM ICE Xext X11

.include "../../mk/bsd.pkg.mk"

# arm32 compiler has an optimizer problem
.if ${OPSYS} == "NetBSD" && ${MACHINE_ARCH} == "arm32"
CFLAGS+=	-O0
.endif
