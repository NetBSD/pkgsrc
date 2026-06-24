# $NetBSD: Makefile,v 1.2 2026/06/24 07:29:56 pin Exp $

#DISTNAME=	Setrixtui-0.4.2
DISTNAME=	setrixtui-0.4.2
#PKGNAME=	${DISTNAME:tl}
CATEGORIES=	games
#MASTER_SITES=	${MASTER_SITE_GITHUB:=Mjoyufull/}
MASTER_SITES=	https://static.crates.io/crates/setrixtui/
EXTRACT_SUFX=	.crate

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Mjoyufull/Setrixtui/
COMMENT=	Tetris Sand game in Ratatui
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
