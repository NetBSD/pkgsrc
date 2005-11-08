# $NetBSD: Makefile,v 1.13 2005/11/08 03:38:34 tv Exp $
#

DISTNAME=		ETM-1.09
PKGNAME=		libetm-1.09
CATEGORIES=		devel
MASTER_SITES=		http://www.snake.net/software/ETM/

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		${MASTER_SITES}
COMMENT=		Exception and termination manager

WRKSRC=			${WRKDIR}/etm
INSTALLATION_DIRS=	include lib

USE_TOOLS+=		nroff

post-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.bak
	${SED} <${WRKSRC}/Makefile.bak >${WRKSRC}/Makefile \
		-e 's|/usr/local|${PREFIX}|'

do-install:
	${INSTALL_DATA} ${WRKSRC}/libetm.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/etm.h ${PREFIX}/include
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libetm
	${NROFF} -ms ${WRKSRC}/etm.ms \
		>${PREFIX}/share/doc/libetm/etm.txt

.include "../../mk/bsd.pkg.mk"
