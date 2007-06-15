# $NetBSD: Makefile,v 1.81 2007/06/15 13:40:35 minskim Exp $
#

DISTNAME=		mathomatic-12.7.2
CATEGORIES=		math
MASTER_SITES=		http://www.panix.com/~gesslein/
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		minskim@NetBSD.org
HOMEPAGE=		http://www.mathomatic.org/
COMMENT=		Small portable symbolic math program

PKG_INSTALLATION_TYPES=	overwrite pkgviews

NO_CONFIGURE=		yes
MAKE_FILE=		makefile

CFLAGS.SunOS+=		-DSOLARIS

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

BUILDLINK_API_DEPENDS.readline+=	readline>=5.1pl1nb1
.include "../../devel/readline/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mathomatic ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/mathomatic.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/doc/* ${WRKSRC}/README.txt \
		${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
