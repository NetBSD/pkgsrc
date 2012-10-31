# $NetBSD: Makefile,v 1.18 2012/10/31 11:17:23 asau Exp $
#

DISTNAME=		TS-1.08
PKGNAME=		libts-1.08
CATEGORIES=		devel
MASTER_SITES=		http://www.snake.net/software/TS/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		${MASTER_SITES}
COMMENT=		Library of simple token-scanning routines

MAKE_JOBS_SAFE=		no

WRKSRC=			${WRKDIR}/tokenscan
INSTALLATION_DIRS=	include lib
USE_TOOLS+=		nroff

post-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.bak
	${SED} <${WRKSRC}/Makefile.bak >${WRKSRC}/Makefile \
		-e "s|/usr/local|${PREFIX}|"

do-install:
	${INSTALL_DATA} ${WRKSRC}/libtokenscan.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/tokenscan.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/libts
	${NROFF} -ms ${WRKSRC}/tokenscan.ms \
		>${DESTDIR}${PREFIX}/share/doc/libts/tokenscan.txt

.include "../../mk/bsd.pkg.mk"
