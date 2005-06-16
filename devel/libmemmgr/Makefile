# $NetBSD: Makefile,v 1.13 2005/06/16 06:57:46 jlam Exp $
#

DISTNAME=		MemMgr-1.04
PKGNAME=		libmemmgr-1.04
CATEGORIES=		devel
MASTER_SITES=		http://www.snake.net/software/MemMgr/

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		${MASTER_SITES}
COMMENT=		Simple memory manager library

WRKSRC=			${WRKDIR}/memmgr-1.04
INSTALLATION_DIRS=	include lib

post-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.bak
	${SED} <${WRKSRC}/Makefile.bak >${WRKSRC}/Makefile \
		-e 's|/usr/local|${PREFIX}|'

do-install:
	${INSTALL_DATA} ${WRKSRC}/libmemmgr.a ${PREFIX}/lib
	${INSTALL_DATA} ${WRKSRC}/memmgr.h ${PREFIX}/include
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libmemmgr
	groff -Tascii -ms ${WRKSRC}/memmgr.ms \
		>${PREFIX}/share/doc/libmemmgr/memmgr.txt

.include "../../devel/libetm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
