# $NetBSD: Makefile,v 1.1 2026/07/02 22:34:07 alnsn Exp $

DISTNAME=	libpoly-0.2.1
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=SRI-CSL/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/SRI-CSL/libpoly
COMMENT=	C library for manipulating polynomials
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=		c c++

CMAKE_CONFIGURE_ARGS+=	-DCMAKE_BUILD_TYPE=Release
CMAKE_CONFIGURE_ARGS+=	-DCMAKE_INSTALL_PREFIX=${PREFIX}

#TEST_DEPENDS+=	${PYPKGPREFIX}-sympy>=1.14.0:../../math/py-sympy

.include "../../devel/cmake/build.mk"
.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
