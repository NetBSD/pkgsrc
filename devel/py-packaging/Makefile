# $NetBSD: Makefile,v 1.22 2024/06/10 05:43:50 adam Exp $

DISTNAME=	packaging-24.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/packaging/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypa/packaging
COMMENT=	Core utilities for Python packages
LICENSE=	modified-bsd OR apache-2.0

DEPENDS+=	${PYPKGPREFIX}-pyparsing>=2.0.2:../../devel/py-pyparsing
TEST_DEPENDS+=	${PYPKGPREFIX}-pretend-[0-9]*:../../devel/py-pretend
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

USE_LANGUAGES=	# none

PYTHON_VERSIONS_INCOMPATIBLE=	27

# as of 23.0:
# 26338 passed, 1 skipped
do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/bootstrap.mk"
.include "../../mk/bsd.pkg.mk"
