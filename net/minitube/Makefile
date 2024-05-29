# $NetBSD: Makefile,v 1.22 2024/05/29 16:33:59 adam Exp $

DISTNAME=	minitube-3.9.3
PKGREVISION=	9
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=flaviotordini/}
GITHUB_PROJECT=	minitube
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://flavio.tordini.org/minitube
COMMENT=	YouTube desktop application
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c++

TOOL_DEPENDS+=	qt5-qttools-[0-9]*:../../x11/qt5-qttools

# MAINTAINER's API key of Google's YouTube Data API v3
# It is strictly prohibited to use this outside pkgsrc.
YT_DATA_API_KEY=	AIzaSyC1J587QO_mrYeJsH4BpAWoSxIuwlW1USc

QTPREFIX=	${PREFIX}/qt5

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QTPREFIX}/bin/qmake \
		"DEFINES+=APP_GOOGLE_API_KEY=${YT_DATA_API_KEY}" \
		"PREFIX=${DESTDIR}${PREFIX}"

.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/mpv/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../x11/qt5-qtx11extras/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
