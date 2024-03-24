# $NetBSD: Makefile,v 1.12 2024/03/24 17:51:05 adam Exp $

DISTNAME=	progressbar2-4.4.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/progressbar2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/WoLpH/python-progressbar
COMMENT=	Text progress bar library for Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel-[0-9]*:../../devel/py-wheel
DEPENDS+=	${PYPKGPREFIX}-utils>=3.8.1:../../devel/py-utils
TEST_DEPENDS+=	${PYPKGPREFIX}-dill>=0.3.6:../../textproc/py-dill
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8>=3.7.7:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun>=0.3.11:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-sphinx>=1.8.5:../../textproc/py-sphinx
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.6.1:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mypy-[0-9]*:../../devel/py-test-mypy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} progressbar progressbar-${PYVERSSUFFIX} || ${TRUE}

do-test:
	${LN} -f ${WRKSRC}/examples.py ${WRKSRC}/tests/examples.py
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
