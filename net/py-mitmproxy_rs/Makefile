# $NetBSD: Makefile,v 1.7 2025/02/04 12:10:02 adam Exp $

DISTNAME=	mitmproxy_rs-0.11.4
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mitmproxy_rs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mitmproxy/mitmproxy-rs
COMMENT=	Mitmproxy's Rust bits
LICENSE=	mit

MAKE_ENV+=	CARGO_NET_OFFLINE=true

PYTHON_VERSIONS_INCOMPATIBLE=	39

BORINGTUN_REV=	e3252d9c4f4c8fc628995330f45369effd4660a1
DISTFILES=	${DEFAULT_DISTFILES}
DISTFILES+=	boringtun-${BORINGTUN_REV}.tar.gz

SITES.boringtun-${BORINGTUN_REV}.tar.gz=	-${MASTER_SITE_GITHUB:=cloudflare/}boringtun/archive/${BORINGTUN_REV}.tar.gz

.include "cargo-depends.mk"

.include "../../devel/py-maturin/tool.mk"
.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
