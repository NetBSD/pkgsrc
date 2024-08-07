# $NetBSD: Makefile,v 1.20 2024/08/07 06:42:48 pin Exp $

DISTNAME=	3.0.0
# This is actually an update from 3.0.0-beta to 3.0.0 release.
# Unfortunately, I made a mistake on previous updates and pushed
# 3.0.0-alpha as 3.0.0 so, use PKGREVISION to handle this.
PKGREVISION=	2
PKGNAME=	wallust-${DISTNAME:S/-beta//}
CATEGORIES=	graphics
MASTER_SITES=	https://codeberg.org/explosion-mental/wallust/archive/

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://codeberg.org/explosion-mental/wallust/
COMMENT=	Generate colors from an image
LICENSE=	mit

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/wallust

#RUST_REQ=	1.79.0
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.79.0 on amd64

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
