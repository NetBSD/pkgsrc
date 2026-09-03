# $NetBSD: Makefile,v 1.1 2026/09/03 05:16:05 adam Exp $

DISTNAME=	jupyter_builder-1.2.2
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

.include "../../lang/python/pyversion.mk"
.if ${PYTHON_VERSION} < 311
DEPENDS+=	${PYPKGPREFIX}-tomli>=0:../../textproc/py-tomli
.endif

.if make(test)
ALLOW_NETWORK_ACCESS=	yes
.endif

pre-test:
	${LN} -fs ${PREFIX}/bin/copier-${PYVERSSUFFIX} ${BUILDLINK_DIR}/bin/copier

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
