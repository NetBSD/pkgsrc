# $NetBSD: Makefile,v 1.23 2026/09/07 16:45:59 adam Exp $

DISTNAME=	falcon-4.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=f/falcon/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://falconframework.org/
COMMENT=	Unladen web framework for building APIs and app backends
LICENSE=	apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-cython>=3.0.8:../../devel/py-cython
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TEST_DEPENDS+=	${PYPKGPREFIX}-requests>=0:../../devel/py-requests
TEST_DEPENDS+=	${PYPKGPREFIX}-yaml>=0:../../textproc/py-yaml

PY_RENAME_BINARIES=	falcon-bench falcon-inspect-app falcon-print-routes

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

# as of 4.0.2
# 1 failed, 3677 passed, 360 skipped

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
