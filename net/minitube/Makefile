# $NetBSD: Makefile,v 1.1 2020/06/05 12:37:19 ryoon Exp $

DISTNAME=	minitube_3.4.orig
PKGNAME=	${DISTNAME:S/.orig$//:S/_/-/}
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_DEBIAN:=pool/main/m/minitube/}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://flavio.tordini.org/minitube
COMMENT=	YouTube desktop application
LICENSE=	gnu-gpl-v3

USE_LANGUAGES=	c++

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}

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
