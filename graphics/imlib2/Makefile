# $NetBSD: Makefile,v 1.13 2003/12/04 19:37:52 xtraeme Exp $
#

DISTNAME=		imlib2-1.1.0
CATEGORIES=		graphics
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=enlightenment/}

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.enlightenment.org/pages/imlib2.html
COMMENT=		Image manipulation library

GNU_CONFIGURE=		YES
USE_X11BASE=		YES
USE_LIBTOOL=		YES
USE_BUILDLINK2=		YES

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/imlib2.pc.in

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386" && ${USE_MMX} != "NO"
CONFIGURE_ARGS+=	--enable-mmx
.endif
BUILD_DEFS+=		USE_MMX

.include "../../devel/pkgconfig/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/libungif/buildlink2.mk"
.include "../../graphics/png/buildlink2.mk"
.include "../../graphics/tiff/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
