# $NetBSD: Makefile,v 1.23 2026/01/07 08:48:19 wiz Exp $
#

DISTNAME=	kdsoap-2.2.0
PKGREVISION=	1
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

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
