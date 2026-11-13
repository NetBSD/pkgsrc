# $NetBSD: Makefile,v 1.2 2026/11/13 20:29:16 alnsn Exp $

DISTNAME=	HiGHS-1.16.0
GITHUB_TAG=	v${PKGVERSION_NOREV}
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=ERGO-Code/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ERGO-Code/HiGHS/
COMMENT=	Solver for large scale sparse linear programming (LP) problems
LICENSE=	mit

USE_LANGUAGES=	c c++

GCC_REQD+=	10

PKGCONFIG_OVERRIDE+=	highs.pc.in

CMAKE_CONFIGURE_ARGS+=	-DALL_TESTS=ON
TEST_TARGET=		test

.include "../../devel/cmake/build.mk"
.include "../../mk/bsd.pkg.mk"
