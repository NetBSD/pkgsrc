# $NetBSD: Makefile,v 1.58 2006/01/21 23:25:02 minskim Exp $
#

DISTNAME=		mathomatic-12.5.5
CATEGORIES=		math
MASTER_SITES=		http://www.panix.com/~gesslein/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		minskim@NetBSD.org
HOMEPAGE=		http://www.mathomatic.com/
COMMENT=		Small portable symbolic math program

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_CONFIGURE=		yes
MAKEFILE=		makefile

CFLAGS.SunOS+=		-DSOLARIS

INSTALLATION_DIRS=	bin man/man1

.include "../../devel/readline/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mathomatic ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mathomatic.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/doc/*.html ${WRKSRC}/README.txt \
		${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
