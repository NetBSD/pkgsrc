# $NetBSD: Makefile,v 1.1 2023/09/15 06:32:00 pin Exp $

DISTNAME=	tetris-tui-0.1.5
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
