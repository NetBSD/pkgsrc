# $NetBSD: Makefile,v 1.24 2026/09/23 07:33:21 mef Exp $

DISTNAME=	gdstk-1.0.1
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

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

.include "../../lang/python/wheel.mk"

.include "../../devel/cmake/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../math/py-numpy/buildlink3.mk"
.include "../../math/qhull/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
