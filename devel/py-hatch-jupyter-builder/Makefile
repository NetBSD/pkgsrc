# $NetBSD: Makefile,v 1.4 2026/10/09 07:12:38 adam Exp $

DISTNAME=	hatch_jupyter_builder-0.10.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hatch-jupyter-builder/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jupyterlab/hatch-jupyter-builder
COMMENT=	Hatch plugin to help build Jupyter packages
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.17:../../devel/py-hatchling
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock>=0:../../devel/py-test-mock

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	hatch-jupyter-builder

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
