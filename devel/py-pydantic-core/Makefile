# $NetBSD: Makefile,v 1.12 2024/08/22 13:32:39 wiz Exp $

DISTNAME=	pydantic_core-2.23.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME:S/_/-/}
PKGREVISION=	1
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=p/pydantic-core/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/pydantic/pydantic-core
COMMENT=	Core functionality for pydantic
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-maturin>=1.7.1:../../devel/py-maturin
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.6.0:../../devel/py-typing-extensions
TEST_DEPENDS+=	${PYPKGPREFIX}-dirty-equals>=0.7.1.post0:../../devel/py-dirty-equals
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=6.92.9:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-test-benchmark-[0-9]*:../../devel/py-test-benchmark
TEST_DEPENDS+=	${PYPKGPREFIX}-test-timeout>=2.2.0:../../devel/py-test-timeout

PYTHON_VERSIONS_INCOMPATIBLE=	27

# as of 2.23.0
# 4467 passed, 62 skipped, 2 xfailed, 1 error

.include "cargo-depends.mk"

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
