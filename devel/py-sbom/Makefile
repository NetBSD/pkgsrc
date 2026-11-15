# $NetBSD: Makefile,v 1.1 2026/11/15 21:45:33 wiz Exp $

DISTNAME=	python_sbom-0.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python_//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/python_sbom/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/tox-dev/python-sbom
COMMENT=	SBOMs for Python distributions
LICENSE=	mit AND apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-fancy-pypi-readme>=0:../../devel/py-hatch-fancy-pypi-readme
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-vcs>=0:../../devel/py-hatch-vcs
DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.28:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-installer>=1.1:../../misc/py-installer
DEPENDS+=	${PYPKGPREFIX}-packageurl>=0.11.1:../../devel/py-packageurl
DEPENDS+=	${PYPKGPREFIX}-packaging>=26.3:../../devel/py-packaging
DEPENDS+=	${PYPKGPREFIX}-zipremove>=0.10:../../archivers/py-zipremove
TEST_DEPENDS+=	${PYPKGPREFIX}-pdm_backend>=2.4:../../devel/py-pdm_backend
TEST_DEPENDS+=	${PYPKGPREFIX}-covdefaults>=2.3:../../devel/py-covdefaults
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=7.1:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=3.16:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-flit_core>=3.12:../../devel/py-flit_core
TEST_DEPENDS+=	${PYPKGPREFIX}-license-expression>=0:../../devel/py-license-expression
TEST_DEPENDS+=	${PYPKGPREFIX}-jsonschema-rs>=0.60.3:../../textproc/py-jsonschema-rs
TEST_DEPENDS+=	${PYPKGPREFIX}-spdx-tools>=0.8.5:../../devel/py-spdx-tools

USE_TOOLS+=	git:test

# as of 0.3.1
# 678 passed, 20 errors

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
