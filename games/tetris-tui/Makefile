# $NetBSD: Makefile,v 1.2 2023/09/20 12:13:37 pin Exp $

DISTNAME=	tetris-tui-0.1.6
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
