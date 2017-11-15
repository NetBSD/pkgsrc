# $NetBSD: Makefile,v 1.3 2017/11/15 14:18:46 adam Exp $

DISTNAME=	backports.functools_lru_cache-1.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/backports.functools_lru_cache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/backports.functools_lru_cache/
COMMENT=	Backport of functools.lru_cache from Python 3.3
LICENSE=	mit

BUILD_DEPENDS+=	${PYPKGPREFIX}-test>=2.8:../../devel/py-test

PYTHON_VERSIONS_ACCEPTED=	27

do-test:
	cd ${WRKSRC}/tests && ${SETENV} ${TEST_ENV} py.test-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
