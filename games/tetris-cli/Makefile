# $NetBSD: Makefile,v 1.1 2022/06/07 10:17:07 pin Exp $

DISTNAME=	tetris-cli-22.66.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=blueOkiris/}
GITHUB_TAG=	1c9c45e8091484e073f179544798c902b93ef3d5

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
