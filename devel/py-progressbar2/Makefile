# $NetBSD: Makefile,v 1.7 2022/10/31 15:27:28 adam Exp $

DISTNAME=	progressbar2-4.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/progressbar2/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/WoLpH/python-progressbar
COMMENT=	Text progress bar library for Python
LICENSE=	modified-bsd

DEPENDS+=	${PYPKGPREFIX}-utils>=3.0.0:../../devel/py-utils
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8>=3.7.7:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun>=0.3.11:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=4.6.9:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=2.6.1:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mypy-[0-9]*:../../devel/py-test-mypy

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-utils

TEST_ENV+=	PYTHONPATH=${WRKSRC}/build/lib

do-test:
	${LN} -f ${WRKSRC}/examples.py ${WRKSRC}/tests/examples.py
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
