# $NetBSD: Makefile,v 1.41 2024/01/21 20:25:30 wiz Exp $

DISTNAME=	dnspython-2.5.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/python-/-/}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=d/dnspython/}

MAINTAINER=	gson@NetBSD.org
HOMEPAGE=	https://www.dnspython.org/
COMMENT=	Python DNS toolkit
LICENSE=	isc

TOOL_DEPENDS+=	${PYPKGPREFIX}-hatchling-[0-9]*:../../devel/py-hatchling
DEPENDS+=	${PYPKGPREFIX}-idna>=2.1:../../www/py-idna
TEST_DEPENDS+=	${PYPKGPREFIX}-test>=5.4.1:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.0.0:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} tests

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
