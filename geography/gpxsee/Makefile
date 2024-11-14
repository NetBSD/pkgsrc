# $NetBSD: Makefile,v 1.30 2024/11/14 22:20:01 wiz Exp $

DISTNAME=	GPXSee-13.26
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	3
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=tumic0/}
GITHUB_PROJECT=	GPXSee

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tumic0/GPXSee/
COMMENT=	GPS log file viewer and analyzer
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=		c++
USE_CXX_FEATURES=	c++11
MAKE_ENV+=		INSTALL_ROOT=${DESTDIR}
QMAKE=			${QTDIR}/bin/qmake

INSTALLATION_DIRS+=	bin share/gpxsee/csv share/gpxsee/maps share/applications share/mime/packages share/pixmaps

do-configure:
	cd ${WRKSRC} && ${QMAKE} PREFIX=${PREFIX} gpxsee.pro

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../geography/qt6-qtpositioning/buildlink3.mk"
.include "../../x11/qt6-qtserialport/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
