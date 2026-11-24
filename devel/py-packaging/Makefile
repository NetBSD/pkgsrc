# $NetBSD: Makefile,v 1.30 2026/11/24 06:40:10 adam Exp $

DISTNAME=	packaging-26.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/packaging/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pypa/packaging
COMMENT=	Core utilities for Python packages
LICENSE=	modified-bsd OR apache-2.0

TEST_DEPENDS+=	${PYPKGPREFIX}-pretend>=0:../../devel/py-pretend
# cyclic dependency
#TEST_DEPENDS+=	${PYPKGPREFIX}-test>=0:../../devel/py-test
#TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=0:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-tomli_w>=0:../../textproc/py-tomli_w

USE_LANGUAGES=	# none

# as of 26.2
# 61512 passed, 1 skipped, 332 deselected

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/bootstrap.mk"
.include "../../mk/bsd.pkg.mk"
