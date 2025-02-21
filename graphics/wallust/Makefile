# $NetBSD: Makefile,v 1.24 2025/02/21 14:35:18 pin Exp $

DISTNAME=	wallust-3.2.0
CATEGORIES=	graphics
MASTER_SITES=	https://static.crates.io/crates/wallust/
EXTRACT_SUFX=	.crate

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://codeberg.org/explosion-mental/wallust/
COMMENT=	Generate colors from an image
LICENSE=	mit

.include "cargo-depends.mk"

#RUST_REQ=	1.84.1
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.84.1 on amd64

INSTALLATION_DIRS=	share/examples/wallust \
			${PKGMANDIR}/man1 \
			${PKGMANDIR}/man5

post-install:
	${INSTALL_DATA} ${WRKSRC}/wallust.toml \
		${DESTDIR}${PREFIX}/share/examples/wallust
	${INSTALL_MAN} ${WRKSRC}/man/wallust.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/wallust.1
	${INSTALL_MAN} ${WRKSRC}/man/wallust-cs.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/wallust-cs.1
	${INSTALL_MAN} ${WRKSRC}/man/wallust-run.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/wallust-run.1
	${INSTALL_MAN} ${WRKSRC}/man/wallust-theme.1 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/wallust-theme.1
	${INSTALL_MAN} ${WRKSRC}/man/wallust.5 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man5/wallust.5

.include "../../lang/rust/cargo.mk"
.include "../../mk/bsd.pkg.mk"
