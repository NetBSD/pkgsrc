# $NetBSD: Makefile,v 1.21 2012/04/03 18:57:22 adam Exp $

DISTNAME=	OpenCV-2.2.0
PKGNAME=	${DISTNAME:S/OpenCV/opencv/}
PKGREVISION=	5
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

SUBST_CLASSES+=		py
SUBST_STAGE.py=		pre-configure
SUBST_FILES.py=		samples/python/*.py
SUBST_SED.py=		-e 's,/usr/bin/python,/usr/bin/env python,'

#CONFIGURE_ARGS+=--with-swig=no
CMAKE_ARGS+=	-D BUILD_NEW_PYTHON_SUPPORT=OFF
# FIXME: should be option.mk'ed instead
CMAKE_ARGS+=	-D WITH_OPENEXR:BOOL=OFF
CMAKE_ARGS+=	-D BUILD_DOXYGEN_DOCS=OFF

post-install:
	${RM} ${DESTDIR}${PREFIX}/include/opencv2/core/*.orig

.include "../../mk/bsd.prefs.mk"

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.include "../../x11/gtk2/buildlink3.mk"
.endif
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
