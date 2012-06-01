# $NetBSD: Makefile,v 1.23 2012/06/01 20:53:56 wiz Exp $

DISTNAME=	OpenCV-2.4.1
PKGNAME=	${DISTNAME:S/OpenCV/opencv/:S/a$//}
CATEGORIES=	graphics devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=opencvlibrary/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	anthony.mallet@laas.fr
HOMEPAGE=	http://opencv.willowgarage.com/
COMMENT=	Library for computer vision problems
LICENSE=	modified-bsd

PKG_DESTDIR_SUPPORT=	user-destdir

USE_CMAKE=		yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
INSTALLATION_DIRS+=	share/doc/opencv/papers share/doc/opencv/ref/pics \
			share/opencv/haarcascades

PKGCONFIG_OVERRIDE+=	opencv.pc.cmake.in

REPLACE_PYTHON+=	samples/python/*.py

WRKSRC=		${WRKDIR}/${DISTNAME:S/a$//}

# includes configure output and paths to gmake etc.
CHECK_WRKREF_SKIP=	${PREFIX}/lib/libopencv_core.so*

.include "options.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.include "../../x11/gtk2/buildlink3.mk"
.endif
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
