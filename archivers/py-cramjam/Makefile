# $NetBSD: Makefile,v 1.4 2024/10/23 21:33:42 wiz Exp $

DISTNAME=	cramjam-2.8.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	archivers python
MASTER_SITES=	${MASTER_SITE_PYPI:=c/cramjam/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/milesgranger/cramjam
COMMENT=	Extremely thin Python bindings to de/compression algorithms in Rust
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-maturin>=0.14:../../devel/py-maturin
TOOL_DEPENDS+=	cmake-[0-9]*:../../devel/cmake
TOOL_DEPENDS+=	nasm-[0-9]*:../../devel/nasm
TEST_DEPENDS+=	${PYPKGPREFIX}-hypothesis-[0-9]*:../../devel/py-hypothesis
TEST_DEPENDS+=	${PYPKGPREFIX}-memory-profiler-[0-9]*:../../devel/py-memory-profiler
TEST_DEPENDS+=	${PYPKGPREFIX}-test-benchmark-[0-9]*:../../devel/py-test-benchmark
TEST_DEPENDS+=	${PYPKGPREFIX}-test-xdist-[0-9]*:../../devel/py-test-xdist

# for isal-sys-0.3.1+496255c
USE_TOOLS+=	autoconf automake
USE_LIBTOOL=	yes

.include "cargo-depends.mk"

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
