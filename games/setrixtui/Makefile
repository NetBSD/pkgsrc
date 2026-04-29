# $NetBSD: Makefile,v 1.1 2026/04/29 19:14:03 wiz Exp $

DISTNAME=	Setrixtui-0.4.1
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=Mjoyufull/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/Mjoyufull/Setrixtui/
COMMENT=	Tetris Sand game in Ratatui
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
