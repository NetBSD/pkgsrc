# $NetBSD: Makefile,v 1.11 2026/04/16 13:02:33 adam Exp $

DISTNAME=	dm_tree-0.1.10
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dm-tree/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/google-deepmind/tree
COMMENT=	Library for working with nested data structures
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-absl-py>=0.6.1:../../devel/py-absl-py
TEST_DEPENDS+=	${PYPKGPREFIX}-attrs>=18.2.0:../../devel/py-attrs
TEST_DEPENDS+=	${PYPKGPREFIX}-numpy>=1.21:../../math/py-numpy
TEST_DEPENDS+=	${PYPKGPREFIX}-wrapt>=1.11.2:../../devel/py-wrapt

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c++
USE_TOOLS+=		cmake gmake

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "../../devel/abseil/buildlink3.mk"
.include "../../devel/py-pybind11/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
