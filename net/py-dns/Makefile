# $NetBSD: Makefile,v 1.36 2023/05/03 18:45:05 wiz Exp $

DISTNAME=	dnspython-2.3.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-/-/}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dnspython/}

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	http://www.dnspython.org/
COMMENT=	Python DNS toolkit
LICENSE=	isc

DEPENDS+=	${PYPKGPREFIX}-cryptodome-[0-9]*:../../security/py-cryptodome
DEPENDS+=	${PYPKGPREFIX}-ecdsa>=0.13:../../security/py-ecdsa
DEPENDS+=	${PYPKGPREFIX}-idna-[0-9]*:../../www/py-idna
# optional:
# doh = ['httpx', 'h2', 'requests', 'requests-toolbelt']
# trio = ['trio']
# curio = ['curio', 'sniffio']
# wmi = ['wmi']
TOOL_DEPENDS+=	${PYPKGPREFIX}-poetry-core>=0:../../devel/py-poetry-core
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm>=0:../../devel/py-setuptools_scm
TOOL_DEPENDS+=	${PYPKGPREFIX}-wheel>=0.35.0:../../devel/py-wheel
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=6.0:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-flake8>=4.0.1:../../devel/py-flake8
TEST_DEPENDS+=	${PYPKGPREFIX}-pylint>=2.7.4:../../devel/py-pylint
TEST_DEPENDS+=	${PYPKGPREFIX}-sphinx>=4.0.0:../../textproc/py-sphinx
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=3.0.0:../../devel/py-test-cov
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=5.4.1:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-twine>=3.1.1:../../net/py-twine

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
