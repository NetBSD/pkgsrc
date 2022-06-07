# $NetBSD: Makefile,v 1.2 2022/06/07 16:25:28 pin Exp $

DISTNAME=	tetris-cli-22.67.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=blueOkiris/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/blueOkiris/tetris-cli/
COMMENT=	Tetris in a terminal
LICENSE=	gnu-gpl-v3

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/tetris-cli \
		${DESTDIR}${PREFIX}/bin

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
