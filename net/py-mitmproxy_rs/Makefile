# $NetBSD: Makefile,v 1.15 2026/10/22 11:04:54 leot Exp $
#
# When updating this, make sure that net/mitmproxy still
# works - usually it also needs to be updated.

DISTNAME=	mitmproxy_rs-0.12.15
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mitmproxy_rs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mitmproxy/mitmproxy-rs
COMMENT=	Mitmproxy's Rust bits
LICENSE=	mit

# See, https://github.com/briansmith/ring/issues/1999
.include "../../mk/compiler/i386-sse2.mk"

MAKE_ENV+=	CARGO_NET_OFFLINE=true
RUST_REQ=	1.86

PYTHON_VERSIONS_INCOMPATIBLE=	311

.include "cargo-depends.mk"

.include "../../devel/py-maturin/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
