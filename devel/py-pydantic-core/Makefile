# $NetBSD: Makefile,v 1.36 2026/04/28 13:05:53 adam Exp $

# NB: pydantic expresses an exact dependency on pydantic-core.  While
# unfortunate, it is actually true, and pydantic with non-matching
# versions of pydantic-core fail to build matrix-synapse.
# https://github.com/pydantic/pydantic/issues/12189#issuecomment-3227083571
DISTNAME=	pydantic_core-2.46.3
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydantic-core/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pydantic/pydantic/tree/main/pydantic-core
COMMENT=	Core functionality for pydantic
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.13.0:../../devel/py-typing-extensions
TEST_DEPENDS+=	${PYPKGPREFIX}-dateutil-[0-9]*:../../time/py-dateutil
TEST_DEPENDS+=	${PYPKGPREFIX}-dirty-equals>=0.7.1.post0:../../devel/py-dirty-equals
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=6.92.9:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-inline-snapshot>=0:../../devel/py-inline-snapshot
TEST_DEPENDS+=	${PYPKGPREFIX}-test-benchmark-[0-9]*:../../devel/py-test-benchmark
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-run-parallel-[0-9]*:../../devel/py-test-run-parallel
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=2.2.0:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-typing-inspection>=0.4.1:../../devel/py-typing-inspection
TEST_DEPENDS+=	${PYPKGPREFIX}-tzdata-[0-9]*:../../time/py-tzdata

# as of 2.27.0
# 4545 passed, 68 skipped, 2 xfailed

.include "cargo-depends.mk"

.include "../../devel/py-maturin/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
