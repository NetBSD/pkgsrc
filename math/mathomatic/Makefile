# $NetBSD: Makefile,v 1.33 2005/03/28 14:52:28 minskim Exp $
#

DISTNAME=		mathomatic-12.2b
CATEGORIES=		math
MASTER_SITES=		http://www.panix.com/~gesslein/
EXTRACT_SUFX=		.tgz

MAINTAINER=		pkgsrc@bjan.freeshell.org
HOMEPAGE=		http://www.panix.com/~gesslein/
COMMENT=		Small portable symbolic math program

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_BUILDLINK3=		yes
NO_CONFIGURE=		yes
MAKEFILE=		makefile

CFLAGS.SunOS+=		-DSOLARIS

INSTALLATION_DIRS=	bin man/man1

.include "../../devel/readline/buildlink3.mk"

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mathomatic ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/mathomatic.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/${PKGBASE}
	${INSTALL_DATA} ${WRKSRC}/doc/*.htm ${WRKSRC}/README.txt	\
		${PREFIX}/share/doc/${PKGBASE}

.include "../../mk/bsd.pkg.mk"
