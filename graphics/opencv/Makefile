# $NetBSD: Makefile,v 1.8 2010/06/13 22:44:39 wiz Exp $
#

DISTNAME=		opencv-1.0.0
PKGREVISION=		5
CATEGORIES=		graphics devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=opencvlibrary/}

MAINTAINER=		anthony.mallet@laas.fr
HOMEPAGE=		http://opencvlibrary.sourceforge.net/
COMMENT=		Library for computer vision problems

PKG_DESTDIR_SUPPORT=	user-destdir

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
INSTALLATION_DIRS+=	share/doc/opencv/papers share/doc/opencv/ref/pics \
			share/opencv/haarcascades

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	opencv.pc.in

SUBST_CLASSES+=		py
SUBST_STAGE.py=		pre-configure
SUBST_FILES.py=		samples/python/*.py
SUBST_SED.py=		-e 's,/usr/bin/python,/usr/bin/env python,'

CONFIGURE_ARGS+=--with-swig=no
CONFIGURE_ARGS+=--with-python=no

.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
