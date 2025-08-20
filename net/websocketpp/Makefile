# $NetBSD: Makefile,v 1.3 2025/08/20 11:35:09 wiz Exp $

DISTNAME=	websocketpp-0.8.2
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=zaphoyd/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.zaphoyd.com/websocketpp
COMMENT=	Header-only C++ library that implements the WebSocket protocol
LICENSE=	modified-bsd # includes other free software, see COPYING

USE_LANGUAGES=	c c++

USE_CXX_FEATURES=	c++11

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_POLICY_VERSION_MINIMUM=3.5

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
