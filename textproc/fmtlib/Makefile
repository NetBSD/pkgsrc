# $NetBSD: Makefile,v 1.1 2018/12/02 17:12:18 adam Exp $

DISTNAME=	fmt-5.2.1
PKGNAME=	${DISTNAME:S/fmt/fmtlib/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=fmtlib/}
GITHUB_PROJECT=	fmt

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fmtlib.net/
COMMENT=	Formatting library
LICENSE=	modified-bsd

USE_CMAKE=	yes
USE_LANGUAGES=	c c++11
TEST_TARGET=	test

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON

.include "../../mk/bsd.pkg.mk"
