# $NetBSD: Makefile,v 1.37 2023/07/19 10:56:21 wiz Exp $

DISTNAME=	dnspython-2.4.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-/-/}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dnspython/}

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://www.dnspython.org/
COMMENT=	Python DNS toolkit
LICENSE=	isc

DEPENDS+=	${PYPKGPREFIX}-idna>=2.1:../../www/py-idna
# optional:
# aioquic
# cryptography
# h2
# httpcore
# httpx
# sniffio
# trio
# wmi
TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=0:../../devel/py-poetry-core
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.40.0:../../devel/py-wheel
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=7.0:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8>=5.0.3:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-pylint>=2.7.4:../../devel/py-pylint
TEST_DEPENDS+=	${PYPKGPREFIX}-sphinx>=4.0.0:../../textproc/py-sphinx
TEST_DEPENDS+=	${PYPKGPREFIX}-mypy>=1.0.1:../../lang/py-mypy
TEST_DEPENDS+=	${PYPKGPREFIX}-black>=23.1.0:../../textproc/py-black
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=5.4.1:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.0.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-twine>=4.0.0:../../net/py-twine

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27 37

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
