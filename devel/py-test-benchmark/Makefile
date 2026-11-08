# $NetBSD: Makefile,v 1.14 2026/11/08 23:14:54 wiz Exp $

DISTNAME=	pytest_benchmark-5.3.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/pytest_/test-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pytest-benchmark/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ionelmc/pytest-benchmark
COMMENT=	Pytest support for benchmarking
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=80:../../devel/py-setuptools
DEPENDS+=	${PYPKGPREFIX}-cpuinfo-[0-9]*:../../sysutils/py-cpuinfo
DEPENDS+=	${PYPKGPREFIX}-test>=8.1:../../devel/py-test
# optional dependency
TEST_DEPENDS+=	${PYPKGPREFIX}-elasticsearch-[0-9]*:../../databases/py-elasticsearch
# optional dependency
TEST_DEPENDS+=	${PYPKGPREFIX}-pygal>=0:../../graphics/py-pygal
# optional: aspectlib (unpackaged)
TEST_DEPENDS+=	${PYPKGPREFIX}-nbmake-[0-9]*:../../devel/py-nbmake
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	py.test-benchmark pytest-benchmark

# as of 5.3.1
# 4 failed, 236 passed, 19 skipped, 3 errors

pre-test:
	${LN} -sf ${DESTDIR}${PREFIX}/bin/pytest-benchmark-${PYVERSSUFFIX} ${BUILDLINK_DIR}/bin/pytest-benchmark
	${LN} -sf ${DESTDIR}${PREFIX}/bin/py.test-benchmark-${PYVERSSUFFIX} ${BUILDLINK_DIR}/bin/py.test-benchmark

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
