# $NetBSD: Makefile,v 1.22.2.1 2012/10/03 12:07:51 spz Exp $
#

DISTNAME=	qlandkartegt-1.4.2
PKGREVISION=	4
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=qlandkartegt/}

MAINTAINER=	jkunz@NetBSD.org
HOMEPAGE=	http://www.qlandkarte.org/
COMMENT=	GPS visualisation and mapping tool, supports Garmin devices
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
USE_CMAKE=	yes
CMAKE_ARGS+=	-DMAN_INSTALL_DIR:PATH=${PREFIX}/${PKGMANDIR}

DEPENDS+=	qlandkartegt-garmindev>=0.3:../../geography/qlandkartegt-garmindev
DEPENDS+=	qt4-sqlite3>=4.8:../../x11/qt4-sqlite3

.include "../../devel/cmake/buildlink3.mk"
.include "../../geography/gpsd/buildlink3.mk"
.include "../../geography/gdal-lib/buildlink3.mk"
.include "../../geography/proj/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../x11/qt4-libs/buildlink3.mk"
.include "../../x11/qt4-tools/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt4-qdbus/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
