# $NetBSD: Makefile,v 1.21 2026/01/12 17:09:58 adam Exp $

DISTNAME=	logbook-1.9.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	devel python
MASTER_SITES=	${MASTER_SITE_PYPI:=L/Logbook/}

MAINTAINER=	kamelderouiche@yahoo.com
HOMEPAGE=	https://logbook.readthedocs.io/
COMMENT=	Logging replacement for Python
LICENSE=	modified-bsd

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools>=78:../../devel/py-setuptools
TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-rust>=1.11.1:../../devel/py-setuptools-rust
DEPENDS+=	${PYPKGPREFIX}-typing-extensions>=4.14.0:../../devel/py-typing-extensions
# compression
DEPENDS+=	${PYPKGPREFIX}-brotli>=1.1.0:../../archivers/py-brotli
TEST_DEPENDS+=	${PYPKGPREFIX}-test-cov-[0-9]*:../../devel/py-test-cov

MAKE_ENV+=	CARGO_BUILD_JOBS=${_MAKE_JOBS_N:U1}

PYTHON_VERSIONS_INCOMPATIBLE=	310

.include "cargo-depends.mk"

.include "../../devel/py-cython/buildlink3.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
