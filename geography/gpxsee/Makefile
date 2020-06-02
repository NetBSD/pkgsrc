# $NetBSD: Makefile,v 1.10 2020/06/02 08:23:57 adam Exp $

DISTNAME=	GPXSee-6.3
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	8
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GITHUB:=tumic0/}
GITHUB_PROJECT=	GPXSee

MAINTAINER=	abs@NetBSD.org
HOMEPAGE=	https://github.com/tumic0/GPXSee/
COMMENT=	GPS log file viewer and analyzer
LICENSE=	gnu-gpl-v3

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
