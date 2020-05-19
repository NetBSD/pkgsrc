# $NetBSD: Makefile,v 1.15 2020/05/19 12:08:31 nia Exp $

DISTNAME=	json-c-0.14
CATEGORIES=	textproc
MASTER_SITES=	https://s3.amazonaws.com/json-c_releases/releases/

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/json-c/json-c/wiki
COMMENT=	JSON library in C
LICENSE=	mit

USE_CMAKE=	yes

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"

PKGCONFIG_OVERRIDE+=	json-c.pc.in

.include "../../mk/bsd.pkg.mk"
