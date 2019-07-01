# $NetBSD: Makefile,v 1.17 2019/07/01 07:15:00 adam Exp $

DISTNAME=	isort-4.3.21
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/isort/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/timothycrosley/isort
COMMENT=	Python utility / library to sort imports
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-lama-[0-9]*:../../devel/py-lama
TEST_DEPENDS+=	${PYPKGPREFIX}-test-[0-9]*:../../devel/py-test

.include "../../lang/python/pyversion.mk"
.if ${_PYTHON_VERSION} == 27
DEPENDS+=	${PYPKGPREFIX}-backports.functools_lru_cache-[0-9]*:../../devel/py-backports.functools_lru_cache
DEPENDS+=	${PYPKGPREFIX}-futures-[0-9]*:../../devel/py-futures
.endif

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} isort isort-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && pytest-${PYVERSSUFFIX} test_isort.py

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
