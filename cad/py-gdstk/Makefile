# $NetBSD: Makefile,v 1.17 2025/01/27 22:39:16 mef Exp $

DISTNAME=	gdstk-0.9.58
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	cad python
MASTER_SITES=	${MASTER_SITE_GITHUB:=heitzmann/}
GITHUB_PROJECT=	gdstk
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/heitzmann/gdstk/
COMMENT=	C++/Python library for GDSII and OASIS files
LICENSE=	boost-license

TOOL_DEPENDS+=	${PYPKGPREFIX}-scikit-build-core-[0-9]*:../../devel/py-scikit-build-core

USE_LANGUAGES+=	c c++

WHEEL_ARGS+=	-C cmake.define.CMAKE_BUILD_WITH_INSTALL_RPATH=1

PRINT_PLIST_AWK+=	{gsub(/${PYVERSSUFFIX:S/.//}/, "$${PYVERS}");}
PLIST_SUBST+=		PYVERS=${PYVERSSUFFIX:S/.//}

.include "../../lang/python/wheel.mk"

.include "../../devel/cmake/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../math/qhull/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
