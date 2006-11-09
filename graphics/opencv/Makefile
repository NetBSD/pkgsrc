# $NetBSD: Makefile,v 1.1.1.1 2006/11/09 05:13:41 uebayasi Exp $
#

DISTNAME=		opencv-1.0.0
CATEGORIES=		graphics devel
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=opencvlibrary/}

MAINTAINER=		anthony.mallet@laas.fr
HOMEPAGE=		http://opencvlibrary.sourceforge.net/
COMMENT=		Library for computer vision problems

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake automake autoconf pkg-config
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
AUTOMAKE_REQD=  	1.9
INSTALLATION_DIRS+=	share/doc/opencv/papers share/doc/opencv/ref/pics \
			share/opencv/haarcascades

GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	opencv.pc.in

CONFIGURE_ARGS+=--with-swig=no
CONFIGURE_ARGS+=--with-python=no

pre-configure:
	cd ${WRKSRC};				\
	automake -a --foreign -i; autoconf

.include "../../x11/gtk2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
