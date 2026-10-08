# $NetBSD: Makefile,v 1.10 2026/10/08 16:43:46 adam Exp $

DISTNAME=	cramjam-2.13.0
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cramjam/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/milesgranger/cramjam
COMMENT=	Extremely thin Python bindings to de/compression algorithms in Rust
LICENSE=	mit

TOOL_DEPENDS+=	cmake>=0:../../devel/cmake
TOOL_DEPENDS+=	nasm>=0:../../devel/nasm
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis>=0:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-memory-profiler>=0:../../devel/py-memory-profiler
TEST_DEPENDS+=	${PYPKGPREFIX}-test-benchmark>=0:../../devel/py-test-benchmark
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist>=0:../../devel/py-test-xdist

# for isal-sys-0.3.1+496255c
USE_TOOLS+=	autoconf automake
USE_LIBTOOL=	yes

RUST_REQ=	1.83

.include "cargo-depends.mk"

.include "../../devel/py-maturin/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
