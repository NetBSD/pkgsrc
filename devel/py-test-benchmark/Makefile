# $NetBSD: Makefile,v 1.13 2026/11/08 19:00:31 wiz Exp $

DISTNAME=	pytest_benchmark-5.3.0
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
TEST_DEPENDS+=	${PYPKGPREFIX}-nbmake-[0-9]*:../../devel/py-nbmake
TEST_DEPENDS+=	${PYPKGPREFIX}-freezegun-[0-9]*:../../devel/py-freezegun

USE_LANGUAGES=	# none

PY_RENAME_BINARIES=	py.test-benchmark pytest-benchmark

# 36 failed, 116 passed, 23 skipped, 79 errors

pre-test:
	${LN} -sf ${DESTDIR}${PREFIX}/bin/pytest-benchmark-${PYVERSSUFFIX} ${BUILDLINK_DIR}/bin/pytest-benchmark
	${LN} -sf ${DESTDIR}${PREFIX}/bin/py.test-benchmark-${PYVERSSUFFIX} ${BUILDLINK_DIR}/bin/py.test-benchmark

.include "../../lang/python/wheel.mk"
.include "../../mk/bsd.pkg.mk"
