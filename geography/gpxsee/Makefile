# $NetBSD: Makefile,v 1.1.1.1 2018/10/19 08:57:22 abs Exp $

GITHUB_PROJECT=	GPXSee
DISTNAME=	6.3
PKGNAME=	${GITHUB_PROJECT:tl}-${DISTNAME}
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=tumic0/}
DIST_SUBDIR=	${GITHUB_PROJECT}

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	https://github.com/tumic0/GPXSee/
COMMENT=	GPS log file viewer and analyzer
LICENSE=	gnu-gpl-v3

WRKSRC=		${WRKDIR}/GPXSee-6.3
USE_LANGUAGES=	c++03
QMAKE=		${QTDIR}/bin/qmake

INSTALLATION_DIRS+=	bin share/gpxsee/csv share/gpxsee/maps share/applications share/mime/packages share/pixmaps

do-configure:
	cd ${WRKSRC} && ${QMAKE} DEFINES+=GPXSEE_GLOBAL_DIR=\\\\\\\"${PREFIX}/share/gpxsee\\\\\\\" gpxsee.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/GPXSee ${DESTDIR}${PREFIX}/bin/gpxsee
	${INSTALL_DATA} ${WRKSRC}/pkg/csv/* ${DESTDIR}${PREFIX}/share/gpxsee/csv
	${INSTALL_DATA} ${WRKSRC}/pkg/maps/* ${DESTDIR}${PREFIX}/share/gpxsee/maps
	${INSTALL_DATA} ${WRKSRC}/pkg/gpxsee.desktop ${DESTDIR}${PREFIX}/share/applications
	${INSTALL_DATA} ${WRKSRC}/pkg/gpxsee.xml ${DESTDIR}${PREFIX}/share/mime/packages
	${INSTALL_DATA} ${WRKSRC}/icons/gpxsee.png ${DESTDIR}${PREFIX}/share/pixmaps

.include "../../x11/qt5-qtbase/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
