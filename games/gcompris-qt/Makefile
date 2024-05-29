# $NetBSD: Makefile,v 1.11 2024/05/29 16:32:35 adam Exp $

DISTNAME=	gcompris-qt-3.1
PKGREVISION=	10
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_KDE:=gcompris/qt/src/}
EXTRACT_SUFX=	.tar.xz
DISTFILES+=	${DEFAULT_DISTFILES} qml-box2d-1308855477d5c7fdae0de3d50168a6765af1ad78.tar.gz
SITES.qml-box2d-1308855477d5c7fdae0de3d50168a6765af1ad78.tar.gz= \
		-https://github.com/qml-box2d/qml-box2d/archive/1308855477d5c7fdae0de3d50168a6765af1ad78.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gcompris.net/
COMMENT=	Educational software suite for children aged 2 to 10
#LICENSE=	many

DEPENDS+=	qt5-qtgraphicaleffects-[0-9]*:../../x11/qt5-qtgraphicaleffects
DEPENDS+=	qt5-qtimageformats-[0-9]*:../../x11/qt5-qtimageformats

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++

post-extract:
	${MV} ${WRKDIR}/qml-box2d-*/* ${WRKSRC}/external/qml-box2d

.include "../../devel/cmake/build.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtmultimedia/buildlink3.mk"
.include "../../x11/qt5-qtsvg/buildlink3.mk"
.include "../../x11/qt5-qttools/buildlink3.mk"
.include "../../x11/qt5-qtquickcontrols2/buildlink3.mk"
.include "../../x11/qt5-qtcharts/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
