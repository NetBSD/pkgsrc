# $NetBSD: Makefile,v 1.22 2012/04/15 03:49:00 markd Exp $

DISTNAME=	OpenCV-2.3.1a
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

.include "options.mk"

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
