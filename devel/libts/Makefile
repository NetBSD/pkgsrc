# $NetBSD: Makefile,v 1.10 2003/12/24 09:53:48 jmmv Exp $
#

DISTNAME=		TS-1.08
PKGNAME=		libts-1.08
WRKSRC=			${WRKDIR}/tokenscan
CATEGORIES=		devel
MASTER_SITES=		http://www.snake.net/software/TS/

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		${MASTER_SITES}
COMMENT=		Library of simple token-scanning routines

post-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.bak
	${SED} <${WRKSRC}/Makefile.bak >${WRKSRC}/Makefile \
		-e "s|/usr/local|${PREFIX}|"

do-install:
	${INSTALL_DATA} ${WRKSRC}/libtokenscan.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/tokenscan.h ${PREFIX}/include
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libts
	groff -Tascii -ms ${WRKSRC}/tokenscan.ms \
		>${PREFIX}/share/doc/libts/tokenscan.txt

.include "../../mk/bsd.pkg.mk"
