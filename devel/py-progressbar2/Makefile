# $NetBSD: Makefile,v 1.21 2026/11/10 09:28:07 adam Exp $

DISTNAME=	progressbar2-4.7.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/progressbar2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/WoLpH/python-progressbar
COMMENT=	Text progress bar library for Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm
DEPENDS+=	${PYPKGPREFIX}-utils>=4.1.4:../../devel/py-utils
TEST_DEPENDS+=	${PYPKGPREFIX}-dill>=0.3.6:../../textproc/py-dill
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8>=3.7.7:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-markupsafe>=2.0:../../textproc/py-markupsafe
TEST_DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.8.5:../../textproc/py-sphinx
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.6.1:../../devel/py-test-cov

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	bar progressbar

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib

PYTHON_VERSIONS_INCOMPATIBLE=	311 # py-sphinx

do-test:
	${LN} -f -s ${WRKSRC}/examples.py ${WRKSRC}/tests/examples.py
	${LN} -f -s ${WRKSRC}/docs ${WRKSRC}/tests/docs
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
