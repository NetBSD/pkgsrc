# $NetBSD: Makefile,v 1.9 2003/12/13 20:14:26 ben Exp $
#

DISTNAME=		ETM-1.09
PKGNAME=		libetm-1.09
WRKSRC=			${WRKDIR}/etm
CATEGORIES=		devel
MASTER_SITES=		http://www.snake.net/software/ETM/

MAINTAINER=		ben@netbsd.org
HOMEPAGE=		${MASTER_SITES}
COMMENT=		Exception and termination manager

post-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.bak
	${SED} <${WRKSRC}/Makefile.bak >${WRKSRC}/Makefile \
		-e 's|/usr/local|${PREFIX}|'

do-install:
	${INSTALL_DATA} ${WRKSRC}/libetm.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/etm.h ${PREFIX}/include
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libetm
	groff -Tascii -ms ${WRKSRC}/etm.ms \
		>${PREFIX}/share/doc/libetm/etm.txt

.include "../../mk/bsd.pkg.mk"
