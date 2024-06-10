# $NetBSD: Makefile,v 1.2 2024/06/10 11:20:19 adam Exp $

DISTNAME=	mitmproxy_rs-0.5.2
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
CATEGORIES=	net python
MASTER_SITES=	${MASTER_SITE_PYPI:=m/mitmproxy_rs/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mitmproxy/mitmproxy-rs
COMMENT=	Mitmproxy's Rust bits
LICENSE=	mit

TOOL_DEPENDS+=	${PYPKGPREFIX}-maturin>=1:../../devel/py-maturin

MAKE_ENV+=	CARGO_NET_OFFLINE=true

# Only for Python 3.10 or newer
PYTHON_VERSIONS_INCOMPATIBLE=	27 38 39

.include "cargo-depends.mk"

.include "../../lang/python/wheel.mk"
.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
