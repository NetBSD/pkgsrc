# $NetBSD: Makefile,v 1.9 2026/09/01 10:10:23 adam Exp $

DISTNAME=	cramjam-2.12.1
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cramjam/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/milesgranger/cramjam
COMMENT=	Extremely thin Python bindings to de/compression algorithms in Rust
LICENSE=	mit

TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake
TOOL_DEPENDS+=	nasm-[0-9]*:../../devel/nasm
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-memory-profiler-[0-9]*:../../devel/py-memory-profiler
TEST_DEPENDS+=	${PYPKGPREFIX}-test-benchmark-[0-9]*:../../devel/py-test-benchmark
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist

# for isal-sys-0.3.1+496255c
USE_TOOLS+=	autoconf automake
USE_LIBTOOL=	yes

RUST_REQ=	1.83

.include "cargo-depends.mk"

.include "../../devel/py-maturin/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
