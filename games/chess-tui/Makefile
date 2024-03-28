# $NetBSD: Makefile,v 1.4 2024/03/28 12:04:56 pin Exp $

DISTNAME=	chess-tui-1.2.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=thomas-mauran/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/thomas-mauran/chess-tui/
COMMENT=	Chess TUI implementation in rust
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
