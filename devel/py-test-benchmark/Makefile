# $NetBSD: Makefile,v 1.2 2020/11/27 10:41:36 jperkin Exp $

DISTNAME=	pytest-benchmark-3.2.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-benchmark/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ionelmc/pytest-benchmark
COMMENT=	Pytest support for benchmarking
LICENSE=	2-clause-bsd

# Optional dependencies, not yet packaged:
#        'aspect': ['aspectlib'],
#        'histogram': ['pygaljs'],
DEPENDS+=	${PYPKGPREFIX}-cpuinfo-[0-9]*:../../sysutils/py-cpuinfo
DEPENDS+=	${PYPKGPREFIX}-pygal-[0-9]*:../../graphics/py-pygal
DEPENDS+=	${PYPKGPREFIX}-elasticsearch-[0-9]*:../../databases/py-elasticsearch
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun

PYTHON_VERSIONED_DEPENDENCIES+=	test
PYTHON_VERSIONS_INCOMPATIBLE=	27	# py-pygal

USE_LANGUAGES=	# none

post-install:
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} py.test-benchmark py.test-benchmark-${PYVERSSUFFIX} || ${TRUE}
	cd ${DESTDIR}${PREFIX}/bin && \
		${MV} pytest-benchmark pytest-benchmark-${PYVERSSUFFIX} || ${TRUE}

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} py.test-${PYVERSSUFFIX}

.include "../../lang/python/versioned_dependencies.mk"
.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
