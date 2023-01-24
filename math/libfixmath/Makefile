# $NetBSD: Makefile,v 1.2 2023/01/24 18:36:30 wiz Exp $

DISTNAME=	libfixmath-0.0.0pre20220623
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=PetteriAimonen/}
GITHUB_PROJECT=	libfixmath
GITHUB_TAG=	809bceac540b14d182589ce4c6f74330a2ff682a

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/PetteriAimonen/libfixmath
COMMENT=	Q16.16 format fixed point operations in C
LICENSE=	mit

USE_LANGUAGES=	c c++11

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON
INSTALL_TARGET=	install

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
