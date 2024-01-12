# $NetBSD: Makefile,v 1.7 2024/01/12 14:02:10 pin Exp $

DISTNAME=	tetris-tui-0.2.10
CATEGORIES=	games
MASTER_SITES=	https://static.crates.io/crates/tetris-tui/
EXTRACT_SUFX=	.crate

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/quantonganh/tetris-tui/
COMMENT=	Tetris in the terminal
LICENSE=	mit

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
