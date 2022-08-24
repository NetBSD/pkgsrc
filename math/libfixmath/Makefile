# $NetBSD: Makefile,v 1.1 2022/08/24 12:49:24 ryoon Exp $

DISTNAME=	libfixmath-0.0.0pre20220623
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=PetteriAimonen/}
GITHUB_PROJECT=	libfixmath
GITHUB_TAG=	809bceac540b14d182589ce4c6f74330a2ff682a

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/PetteriAimonen/libfixmath
COMMENT=	Q16.16 format fixed point operations in C
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++11

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON
INSTALL_TARGET=	install

.include "../../mk/bsd.pkg.mk"
