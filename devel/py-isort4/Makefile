# $NetBSD: Makefile,v 1.3 2022/01/05 20:47:35 wiz Exp $

DISTNAME=	isort-4.3.21
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=i/isort/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/timothycrosley/isort
COMMENT=	Python utility / library to sort imports
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-lama-[0-9]*:../../devel/py-lama

PYTHON_VERSIONED_DEPENDENCIES=	test:test

USE_PKG_RESOURCES=	yes

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
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX} test_isort.py

.include "../../lang/python/egg.mk"
.include "../../lang/python/versioned_dependencies.mk"
.include "../../mk/bsd.pkg.mk"
