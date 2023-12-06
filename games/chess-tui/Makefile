# $NetBSD: Makefile,v 1.1 2023/12/06 10:14:02 pin Exp $

DISTNAME=	chess-tui-1.0.1
CATEGORIES=	games
MASTER_SITES=	https://static.crates.io/crates/chess-tui/
EXTRACT_SUFX=	.crate

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/thomas-mauran/chess-tui/
COMMENT=	Chess TUI implementation in rust
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
