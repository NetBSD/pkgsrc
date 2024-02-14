# $NetBSD: Makefile,v 1.18 2024/02/14 10:31:58 pin Exp $

DISTNAME=	3.0.0-alpha
PKGNAME=	wallust-${DISTNAME:S/-alpha//}
CATEGORIES=	graphics
MASTER_SITES=	https://codeberg.org/explosion-mental/wallust/archive/

MAINTAINER=	pin@NetBSD.org
HOMEPAGE=	https://codeberg.org/explosion-mental/wallust/
COMMENT=	Generate colors from an image
LICENSE=	mit

.include "cargo-depends.mk"

WRKSRC=		${WRKDIR}/wallust

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
