# $NetBSD: Makefile,v 1.10 2026/01/14 13:07:03 adam Exp $

DISTNAME=	pytest_run_parallel-0.8.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//:S/_/-/g}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-run-parallel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Quansight-Labs/pytest-run-parallel
COMMENT=	Simple pytest plugin to run tests concurrently
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-test>=6.2.0:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-coverage>=7.8:../../devel/py-coverage
TEST_DEPENDS+=	${PYPKGPREFIX}-test-order>0:../../devel/py-test-order
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>0:../../devel/py-test-xdist

USE_LANGUAGES=	# none

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
