# $NetBSD: Makefile,v 1.45 2026/05/01 05:21:59 pin Exp $

DISTNAME=	difftastic-0.69.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Wilfred/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/Wilfred/difftastic/
COMMENT=	Syntax-aware diffing tool
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.85.0
USE_TOOLS+=	gmake pkg-config

USE_LANGUAGES+=		c c++
USE_CXX_FEATURES=	c++17

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
