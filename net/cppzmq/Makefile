# $NetBSD: Makefile,v 1.3 2023/01/01 15:42:22 adam Exp $

DISTNAME=	cppzmq-4.9.0
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=zeromq/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/zeromq/cppzmq
COMMENT=	C++ binding for libzmq
LICENSE=	mit

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
TEST_TARGET=	test

# needed for building unit tests
.include "../../devel/catch2/buildlink3.mk"
.include "../../net/zeromq/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
