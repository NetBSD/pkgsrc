# $NetBSD: Makefile,v 1.13 2025/12/12 12:07:03 adam Exp $
#
# When updating this, make sure that net/mitmproxy still
# works - usually it also needs to be updated.

DISTNAME=	mitmproxy_rs-0.12.8
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

PYTHON_VERSIONS_INCOMPATIBLE=	310 311

BORINGTUN_REV=	2f3c85f5c4a601018c10b464b1ca890d9504bf6e
DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	boringtun-${BORINGTUN_REV}.tar.gz

SITES.boringtun-${BORINGTUN_REV}.tar.gz=	-${MASTER_SITE_GITHUB:=cloudflare/}boringtun/archive/${BORINGTUN_REV}.tar.gz

.include "cargo-depends.mk"

.include "../../devel/py-maturin/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
