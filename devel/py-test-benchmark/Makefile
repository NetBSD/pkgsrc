# $NetBSD: Makefile,v 1.10 2025/11/04 11:56:59 adam Exp $

DISTNAME=	pytest_benchmark-5.2.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pytest_/test-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-benchmark/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ionelmc/pytest-benchmark
COMMENT=	Pytest support for benchmarking
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cpuinfo-[0-9]*:../../sysutils/py-cpuinfo
DEPENDS+=	${PYPKGPREFIX}-test>=8.1:../../devel/py-test
TEST_DEPENDS+=	${PYPKGPREFIX}-elasticsearch-[0-9]*:../../databases/py-elasticsearch
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun

USE_LANGUAGES=	# none

post-install:
.for bin in py.test-benchmark pytest-benchmark
	cd ${DESTDIR}${PREFIX}/bin && \
	${MV} ${bin} ${bin}-${PYVERSSUFFIX} || ${TRUE}
.endfor

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
