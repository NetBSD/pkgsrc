# $NetBSD: Makefile,v 1.2 2022/11/15 10:01:56 adam Exp $

DISTNAME=	pytest-trio-0.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-trio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-trio/pytest-trio
COMMENT=	Python testing tool for trio
LICENSE=	mit OR apache-2.0

DEPENDS+=	${PYPKGPREFIX}-outcome>=1.1.0:../../devel/py-outcome
DEPENDS+=	${PYPKGPREFIX}-test>=7.2.0:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-trio>=0.22.0:../../devel/py-trio
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=6.56.4:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.0.0:../../devel/py-test-cov

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# does not run
# Defining 'pytest_plugins' in a non-top-level conftest is no longer supported:
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} pytest_trio

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
