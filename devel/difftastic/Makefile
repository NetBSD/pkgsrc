# $NetBSD: Makefile,v 1.25 2023/08/17 02:43:21 pin Exp $

DISTNAME=	difftastic-0.50.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=Wilfred/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://github.com/Wilfred/difftastic/
COMMENT=	Syntax-aware diffing tool
LICENSE=	mit

.include "cargo-depends.mk"

USE_TOOLS+=	pkg-config

USE_LANGUAGES+=	c c++17

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
