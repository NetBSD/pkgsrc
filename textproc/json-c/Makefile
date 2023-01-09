# $NetBSD: Makefile,v 1.19 2023/01/09 18:16:14 khorben Exp $

DISTNAME=	json-c-0.16
CATEGORIES=	textproc
MASTER_SITES=	https://s3.amazonaws.com/json-c_releases/releases/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/json-c/json-c/wiki
COMMENT=	JSON library in C
LICENSE=	mit

USE_CMAKE=	yes

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"
CMAKE_ARGS+=	-DDISABLE_WERROR=ON

PKGCONFIG_OVERRIDE+=	json-c.pc.in

.include "options.mk"

.include "../../mk/bsd.pkg.mk"
