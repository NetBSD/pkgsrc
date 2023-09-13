# $NetBSD: Makefile,v 1.3 2023/09/13 20:36:10 pin Exp $

DISTNAME=	tetris-cli-23.96.1
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
