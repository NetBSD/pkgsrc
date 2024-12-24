# $NetBSD: Makefile,v 1.25 2024/12/24 22:14:39 adam Exp $

DISTNAME=	pydantic_core-2.27.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydantic-core/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pydantic/pydantic-core
COMMENT=	Core functionality for pydantic
LICENSE=	mit

DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.6.0:../../devel/py-typing-extensions
TEST_DEPENDS+=	${PYPKGPREFIX}-dirty-equals>=0.7.1.post0:../../devel/py-dirty-equals
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=6.92.9:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-test-benchmark-[0-9]*:../../devel/py-test-benchmark
TEST_DEPENDS+=	${PYPKGPREFIX}-test-mock-[0-9]*:../../devel/py-test-mock
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=2.2.0:../../devel/py-test-timeout
TEST_DEPENDS+=	${PYPKGPREFIX}-inline-snapshot>=0:../../devel/py-inline-snapshot

# as of 2.27.0
# 4545 passed, 68 skipped, 2 xfailed

.include "cargo-depends.mk"

.include "../../devel/py-maturin/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
