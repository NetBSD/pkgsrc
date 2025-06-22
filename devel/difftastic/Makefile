# $NetBSD: Makefile,v 1.41 2025/06/22 07:46:49 wiz Exp $

DISTNAME=	difftastic-0.64.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Wilfred/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/Wilfred/difftastic/
COMMENT=	Syntax-aware diffing tool
LICENSE=	mit

.include "cargo-depends.mk"

RUST_REQ=	1.74.1
USE_TOOLS+=	gmake pkg-config

USE_LANGUAGES+=		c c++
USE_CXX_FEATURES=	c++17

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
