# $NetBSD: Makefile,v 1.6 2023/04/27 21:03:28 pin Exp $

DISTNAME=	wallust-2.2.0
CATEGORIES=	graphics
MASTER_SITES=	https://static.crates.io/crates/wallust/
EXTRACT_SUFX=	.crate

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://codeberg.org/explosion-mental/wallust
COMMENT=	Generate colors from an image
LICENSE=	mit

.include "cargo-depends.mk"

INSTALLATION_DIRS=	bin share/examples/wallust

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/target/release/${PKGBASE} \
		${DESTDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/wallust.toml \
		${DESTDIR}${PREFIX}/share/examples/wallust

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
