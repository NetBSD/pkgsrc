# $NetBSD: Makefile,v 1.3 2026/10/16 17:54:56 adam Exp $

DISTNAME=	jupyter_builder-1.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=j/jupyter-builder/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jupyterlab/jupyter-builder
COMMENT=	JupyterLab build tools
LICENSE=	modified-bsd AND mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatch-nodejs-version>=0.3.2:../../devel/py-hatch-nodejs-version
TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling>=1.21.1:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-jupyter_core>=0:../../devel/py-jupyter_core
DEPENDS+=	${PYPKGPREFIX}-traitlets>=0:../../devel/py-traitlets
TEST_DEPENDS+=	${PYPKGPREFIX}-copier>=9.3:../../misc/py-copier
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=7:../../devel/py-test-cov

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	jlpm jupyter-builder

.if make(test)
ALLOW_NETWORK_ACCESS=	yes
.endif

pre-test:
	${LN} -fs ${PREFIX}/bin/copier-${PYVERSSUFFIX} ${BUILDLINK_DIR}/bin/copier

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
