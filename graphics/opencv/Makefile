# $NetBSD: Makefile,v 1.17 2011/11/01 06:01:41 sbd Exp $
#

DISTNAME=		OpenCV-2.2.0
PKGNAME=		${DISTNAME:S/OpenCV/opencv/}
PKGREVISION=		3
CATEGORIES=		graphics devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=opencvlibrary/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		anthony.mallet@laas.fr
HOMEPAGE=		http://opencvlibrary.sourceforge.net/
COMMENT=		Library for computer vision problems

PKG_DESTDIR_SUPPORT=	user-destdir

USE_CMAKE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
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

.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jasper/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
