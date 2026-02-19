# $NetBSD: Makefile,v 1.25 2026/02/19 22:56:39 wiz Exp $

DISTNAME=	kdsoap-2.2.0
PKGREVISION=	2
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
