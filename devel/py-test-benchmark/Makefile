# $NetBSD: Makefile,v 1.6 2022/11/20 23:24:21 adam Exp $

DISTNAME=	pytest-benchmark-4.0.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/py//}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-benchmark/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ionelmc/pytest-benchmark
COMMENT=	Pytest support for benchmarking
LICENSE=	2-clause-bsd

DEPENDS+=	${PYPKGPREFIX}-cpuinfo-[0-9]*:../../sysutils/py-cpuinfo
DEPENDS+=	${PYPKGPREFIX}-pygal-[0-9]*:../../graphics/py-pygal
DEPENDS+=	${PYPKGPREFIX}-test>=3.8:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-elasticsearch-[0-9]*:../../databases/py-elasticsearch
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun

USE_LANGUAGES=	# none

USE_PKG_RESOURCES=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27	# py-pygal

post-install:
.for bin in py.test-benchmark pytest-benchmark
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

do-test:
	cd ${WRKSRC} && ${SETENV} ${TEST_ENV} pytest-${PYVERSSUFFIX}

.include "../../lang/python/egg.mk"
.include "../../mk/bsd.pkg.mk"
