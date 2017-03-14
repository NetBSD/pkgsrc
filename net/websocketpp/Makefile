# $NetBSD: Makefile,v 1.1 2017/03/14 13:09:37 wiz Exp $

DISTNAME=	websocketpp-0.7.0
CATEGORIES=	net devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=zaphoyd/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.zaphoyd.com/websocketpp
COMMENT=	Header-only C++ library that implements the WebSocket protocol
#LICENSE=	basically BSD, but includes other free software, see COPYING

USE_CMAKE=	yes
USE_LANGUAGES=	c c++

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
