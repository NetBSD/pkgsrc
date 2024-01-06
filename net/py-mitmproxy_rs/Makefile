# $NetBSD: Makefile,v 1.1 2024/01/06 23:24:02 leot Exp $

DISTNAME=	mitmproxy_rs-0.5.1
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
