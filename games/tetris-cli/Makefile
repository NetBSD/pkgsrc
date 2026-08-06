# $NetBSD: Makefile,v 1.4 2026/08/06 13:18:26 pin Exp $

DISTNAME=	tetris-cli-26.61.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=blueOkiris/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/blueOkiris/tetris-cli/
COMMENT=	Tetris in a terminal
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
