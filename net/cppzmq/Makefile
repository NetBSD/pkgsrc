# $NetBSD: Makefile,v 1.4 2023/07/18 04:53:45 adam Exp $

DISTNAME=	cppzmq-4.10.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=zeromq/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zeromq/cppzmq
COMMENT=	C++ binding for libzmq
LICENSE=	mit

USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
TEST_TARGET=	test

# needed for building unit tests
.include "../../devel/catch2/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../net/zeromq/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
