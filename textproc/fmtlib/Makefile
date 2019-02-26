# $NetBSD: Makefile,v 1.2 2019/02/26 10:58:25 adam Exp $

DISTNAME=	fmt-5.3.0
PKGNAME=	${DISTNAME:S/fmt/fmtlib/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=fmtlib/}
GITHUB_PROJECT=	fmt

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://fmtlib.net/
COMMENT=	Formatting library
LICENSE=	modified-bsd

USE_CMAKE=		yes
USE_LANGUAGES=		c c++11
PKGCONFIG_OVERRIDE=	support/cmake/fmt.pc.in
TEST_TARGET=		test

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON

.include "../../mk/bsd.pkg.mk"
