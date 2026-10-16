# $NetBSD: Makefile,v 1.6 2026/10/16 19:44:01 adam Exp $

DISTNAME=	pydemumble-0.1.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	lang python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydemumble/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/angr/pydemumble
COMMENT=	Python wrapper library for demumble
LICENSE=	modified-bsd

TOOL_DEPENDS+=	ninja-build>0:../../devel/ninja-build
# bundled
#TOOL_DEPENDS+=	${PYPKGPREFIX}-nanobind>=1.3.2:../../devel/py-nanobind
TOOL_DEPENDS+=	${PYPKGPREFIX}-scikit-build-core>=0.10:../../devel/py-scikit-build-core

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++
USE_TOOLS+=		cmake
#  for #if __has_builtin(__builtin_expect)
GCC_REQD+=		10

PYTHON_VERSIONS_INCOMPATIBLE=	311

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
