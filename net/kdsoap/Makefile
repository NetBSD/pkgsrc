# $NetBSD: Makefile,v 1.26 2026/05/14 16:41:45 ryoon Exp $

DISTNAME=	kdsoap-2.2.0
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=KDAB/}
GITHUB_PROJECT=	KDSoap
GITHUB_RELEASE=	${DISTNAME}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/KDAB/KDSoap
COMMENT=	Qt-based client-side and server-side SOAP component
LICENSE=	gnu-agpl-v3

.include "../../devel/cmake/build.mk"

USE_LANGUAGES=	c c++

CMAKE_CONFIGURE_ARGS+=	-DKDSoap_QT6=ON

BUILDLINK_TRANSFORM+=	rm:-Wl,--fatal-warnings

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
