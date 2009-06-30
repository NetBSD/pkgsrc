# $NetBSD: Makefile,v 1.16 2009/06/30 00:07:13 joerg Exp $
#

DISTNAME=		ETM-1.09
PKGNAME=		libetm-1.09
CATEGORIES=		devel
MASTER_SITES=		http://www.snake.net/software/ETM/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		${MASTER_SITES}
COMMENT=		Exception and termination manager

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=		no

WRKSRC=			${WRKDIR}/etm
INSTALLATION_DIRS=	include lib

USE_TOOLS+=		nroff

post-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.bak
	${SED} <${WRKSRC}/Makefile.bak >${WRKSRC}/Makefile \
		-e 's|/usr/local|${PREFIX}|'

do-install:
	${INSTALL_DATA} ${WRKSRC}/libetm.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/etm.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/libetm
	${NROFF} -ms ${WRKSRC}/etm.ms \
		>${DESTDIR}${PREFIX}/share/doc/libetm/etm.txt

.include "../../mk/bsd.pkg.mk"
