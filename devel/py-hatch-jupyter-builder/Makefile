# $NetBSD: Makefile,v 1.3 2024/04/03 08:56:37 adam Exp $

DISTNAME=	hatch_jupyter_builder-0.9.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=h/hatch-jupyter-builder/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jupyterlab/hatch-jupyter-builder
COMMENT=	Hatch plugin to help build Jupyter packages
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.17:../../devel/py-hatchling
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} hatch-jupyter-builder hatch-jupyter-builder-${PYVERSSUFFIX} || ${TRUE}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
