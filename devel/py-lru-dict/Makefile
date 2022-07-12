# $NetBSD: Makefile,v 1.4 2022/07/12 07:43:12 adam Exp $

DISTNAME=	lru-dict-1.1.8
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=l/lru-dict/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/amitdev/lru-dict
COMMENT=	Dict-like LRU container
LICENSE=	mit

TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

PYTHON_VERSIONS_INCOMPATIBLE=	27 # py-test

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} test

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
