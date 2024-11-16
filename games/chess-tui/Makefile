# $NetBSD: Makefile,v 1.5 2024/11/16 20:09:23 pin Exp $

DISTNAME=	chess-tui-1.3.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=thomas-mauran/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/thomas-mauran/chess-tui/
COMMENT=	Chess TUI implementation in rust
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
