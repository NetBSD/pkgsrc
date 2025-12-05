# $NetBSD: Makefile,v 1.3 2025/12/05 20:57:34 wiz Exp $

DISTNAME=	pytest-trio-0.8.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-trio/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/python-trio/pytest-trio
COMMENT=	Python testing tool for trio
LICENSE=	mit OR apache-2.0

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=0:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-outcome>=1.1.0:../../devel/py-outcome
DEPENDS+=	${PYPKGPREFIX}-test>=7.2.0:../../devel/py-test
DEPENDS+=	${PYPKGPREFIX}-trio>=0.25.1:../../devel/py-trio
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=6.56.4:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov>=4.0.0:../../devel/py-test-cov

USE_LANGUAGES=	# none

# does not run
# Defining 'pytest_plugins' in a non-top-level conftest is no longer supported:
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} pytest_trio

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
