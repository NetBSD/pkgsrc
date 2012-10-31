# $NetBSD: Makefile,v 1.17 2012/10/31 11:17:17 asau Exp $
#

DISTNAME=		MemMgr-1.04
PKGNAME=		libmemmgr-1.04
CATEGORIES=		devel
MASTER_SITES=		http://www.snake.net/software/MemMgr/

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		${MASTER_SITES}
COMMENT=		Simple memory manager library

WRKSRC=			${WRKDIR}/memmgr-1.04
INSTALLATION_DIRS=	include lib

post-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.bak
	${SED} <${WRKSRC}/Makefile.bak >${WRKSRC}/Makefile \
		-e 's|/usr/local|${PREFIX}|'

do-install:
	${INSTALL_DATA} ${WRKSRC}/libmemmgr.a ${DESTDIR}${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/memmgr.h ${DESTDIR}${PREFIX}/include
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/libmemmgr
	groff -Tascii -ms ${WRKSRC}/memmgr.ms \
		>${DESTDIR}${PREFIX}/share/doc/libmemmgr/memmgr.txt

.include "../../devel/libetm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
