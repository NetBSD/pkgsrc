# $NetBSD: Makefile,v 1.23 2025/01/11 14:31:24 ryoon Exp $

DISTNAME=	json-c-0.18
CATEGORIES=	textproc
MASTER_SITES=	https://s3.amazonaws.com/json-c_releases/releases/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/json-c/json-c/wiki
COMMENT=	JSON library in C
LICENSE=	mit

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"
CMAKE_CONFIGURE_ARGS+=	-DDISABLE_WERROR=ON

PKGCONFIG_OVERRIDE+=	json-c.pc.in

.include "options.mk"

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
