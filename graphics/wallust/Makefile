# $NetBSD: Makefile,v 1.15 2023/12/21 21:24:09 pin Exp $

DISTNAME=	wallust-2.8.0
CATEGORIES=	graphics
MASTER_SITES=	https://static.crates.io/crates/wallust/
EXTRACT_SUFX=	.crate

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://codeberg.org/explosion-mental/wallust
COMMENT=	Generate colors from an image
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	share/examples/wallust

post-install:
	${INSTALL_DATA} ${WRKSRC}/wallust.toml \
		${DESTDIR}${PREFIX}/share/examples/wallust

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
