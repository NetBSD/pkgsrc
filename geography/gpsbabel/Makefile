# $NetBSD: Makefile,v 1.58 2024/08/30 19:28:09 gdt Exp $
#

GITHUB_PROJECT=	gpsbabel
VERSION=	1.9.0
GH_VERSION=	1_9_0
GITHUB_TAG=	refs/tags/gpsbabel_${GH_VERSION}
DISTNAME=	gpsbabel_${GH_VERSION}
PKGNAME=	gpsbabel-${VERSION}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=GPSBabel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gpsbabel.org/
#HOMEPAGE=	https://github.com/gpsbabel/gpsbabel
COMMENT=	Utility to convert and fetch GPS related data
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${GITHUB_PROJECT}-${DISTNAME}

USE_LANGUAGES+=		c c++
USE_CXX_FEATURES+=	c++11
USE_TOOLS+=		pkg-config

INSTALLATION_DIRS+=	bin
do-install:
	${INSTALL} ${WRKSRC}/${CMAKE_BUILD_DIR}/gpsbabel ${DESTDIR}${PREFIX}/bin

.include "../../devel/cmake/build.mk"

.include "../../devel/libusb1/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtserialport/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtwebengine/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
