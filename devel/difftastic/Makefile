# $NetBSD: Makefile,v 1.38 2024/12/21 16:30:53 pin Exp $

DISTNAME=	difftastic-0.62.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Wilfred/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/Wilfred/difftastic/
COMMENT=	Syntax-aware diffing tool
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.74.1
USE_TOOLS+=	pkg-config

USE_LANGUAGES+=	c c++17

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
