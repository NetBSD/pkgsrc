# $NetBSD: Makefile,v 1.5 2024/01/15 09:41:53 nros Exp $

DISTNAME=	cppzmq-4.10.0
PKGREVISION=	1
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


# for catch2 v2 -> v3 migration
SUBST_CLASSES+=		catch2v3
SUBST_STAGE.catch2v3=	pre-configure
SUBST_FILES.catch2v3+=	tests/*.cpp
SUBST_FILES.catch2v3+=	tests/*.hpp
SUBST_FILES.catch2v3+=	tests/CMakeLists.txt
SUBST_SED.catch2v3+=	-e 's,<catch2/catch.hpp>,<catch2/catch_all.hpp>,g'
SUBST_SED.catch2v3+=	-e 's,Catch2::Catch2,Catch2::Catch2WithMain,g'

# needed for building unit tests
.include "../../devel/catch2/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../net/zeromq/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
