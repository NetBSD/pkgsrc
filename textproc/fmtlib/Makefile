# $NetBSD: Makefile,v 1.9 2020/11/26 09:31:18 adam Exp $

DISTNAME=	fmt-7.1.3
PKGNAME=	${DISTNAME:S/fmt/fmtlib/}
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=fmtlib/}
GITHUB_PROJECT=	fmt

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://fmt.dev/
COMMENT=	Formatting library
LICENSE=	mit

USE_CMAKE=		yes
USE_LANGUAGES=		c c++11
PKGCONFIG_OVERRIDE=	support/cmake/fmt.pc.in
TEST_ENV+=		LD_LIBRARY_PATH=${WRKSRC}
TEST_TARGET=		test

CMAKE_ARGS+=	-DBUILD_SHARED_LIBS=ON

.include "../../mk/bsd.pkg.mk"
