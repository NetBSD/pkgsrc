# $NetBSD: Makefile,v 1.21 2023/08/24 09:23:14 wiz Exp $

DISTNAME=	json-c-0.17
CATEGORIES=	textproc
MASTER_SITES=	https://s3.amazonaws.com/json-c_releases/releases/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/json-c/json-c/wiki
COMMENT=	JSON library in C
LICENSE=	mit

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"
CMAKE_ARGS+=	-DDISABLE_WERROR=ON

PKGCONFIG_OVERRIDE+=	json-c.pc.in

.include "options.mk"

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
