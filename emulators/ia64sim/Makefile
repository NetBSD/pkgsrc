# $NetBSD: Makefile,v 1.18 2012/10/03 12:55:14 asau Exp $

DISTNAME=		ia64sim
PKGNAME=		ia64sim-0.5
CATEGORIES=		emulators
MASTER_SITES=		http://www.boo.net/~jasonp/
EXTRACT_SUFX=		.zip

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.boo.net/~jasonp/
COMMENT=		IA64 simulator (Intel(R) Architecture 64)

USE_TOOLS+=		gmake
DIST_SUBDIR=		${PKGNAME_NOREV}
WRKSRC=			${WRKDIR}/home/chuck/ia64simcc

MAKE_FILE=		makefile.unx
INSTALLATION_DIRS=	bin share/doc/ia64sim

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ia64sim ${DESTDIR}${PREFIX}/bin/ia64sim
	${INSTALL_DATA} ${WRKSRC}/doc/ia64user.txt ${DESTDIR}${PREFIX}/share/doc/ia64sim

.include "../../mk/bsd.pkg.mk"
