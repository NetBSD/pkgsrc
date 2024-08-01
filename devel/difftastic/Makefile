# $NetBSD: Makefile,v 1.36 2024/08/01 17:43:13 pin Exp $

DISTNAME=	difftastic-0.60.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Wilfred/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/Wilfred/difftastic/
COMMENT=	Syntax-aware diffing tool
LICENSE=	mit

.include "cargo-depends.mk"

# Upstreams goal is to support at least 12 months of Rust versions,
# and also the Rust version on Debian stable (# currently 1.63).
# Unfortunately tree-sitter 0.20.10 has an MSRV of 1.65, and it has
# a bugfix upstream wants.
RUST_REQ=	1.65.0
USE_TOOLS+=	pkg-config

USE_LANGUAGES+=	c c++17

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
