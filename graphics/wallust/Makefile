# $NetBSD: Makefile,v 1.29 2026/02/26 12:49:51 pin Exp $

DISTNAME=	wallust-3.5.2
CATEGORIES=	graphics
MASTER_SITES=	${HOMEPAGE}archive/
SITES.${DISTNAME}.tar.gz=	-${MASTER_SITES}${PKGVERSION_NOREV}${EXTRACT_SUFX}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://codeberg.org/explosion-mental/wallust/
COMMENT=	Generate colors from an image
LICENSE=	mit

.include "cargo-depends.mk"

#RUST_REQ=	1.93.1
#Upstream does not state the required MSRV.
#This package is confirmed to build with Rust 1.93.1 on amd64

WRKSRC=		${WRKDIR}/${PKGBASE}

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
