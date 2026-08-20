# $NetBSD: Makefile,v 1.3 2026/08/20 10:42:42 adam Exp $

DISTNAME=	uv_dynamic_versioning-0.14.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=u/uv-dynamic-versioning/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ninoseki/uv-dynamic-versioning
COMMENT=	Dynamic versioning based on VCS tags for uv/hatch project
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-dunamai>=1.26.1:../../devel/py-dunamai
DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.28:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-jinja2>=3.0:../../textproc/py-jinja2
DEPENDS+=	${PYPKGPREFIX}-tomlkit>=0.13:../../textproc/py-tomlkit
TEST_DEPENDS+=	${PYPKGPREFIX}-gitpython>=0:../../devel/py-gitpython

PY_RENAME_BINARIES=	uv-dynamic-versioning

# as of 0.14.0
# 1 failed, 28 passed, 27 errors

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
