# $NetBSD: Makefile,v 1.6 2018/09/27 20:27:38 tnn Exp $

DISTNAME=	backports.functools_lru_cache-1.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=b/backports.functools_lru_cache/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/jaraco/backports.functools_lru_cache/
COMMENT=	Backport of functools.lru_cache from Python 3.3
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-backports-[0-9]*:../../devel/py-backports
BUILD_DEPENDS+=	${PYPKGPREFIX}-test>=2.8:../../devel/py-test
BUILD_DEPENDS+=	${PYPKGPREFIX}-setuptools_scm-[0-9]*:../../devel/py-setuptools_scm

PYTHON_VERSIONS_ACCEPTED=	27

do-test:
	cd ${WRKSRC}/tests && ${SETENV} ${TEST_ENV} py.test-${PYVERSSUFFIX}

post-install:
	rm ${DESTDIR}${PREFIX}/${PYSITELIB}/backports/__init__.*

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
