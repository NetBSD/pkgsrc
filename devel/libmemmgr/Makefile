# $NetBSD: Makefile,v 1.6 2003/12/11 19:24:33 ben Exp $
#

DISTNAME=		MemMgr-1.04
PKGNAME=		libmemmgr-1.04
WRKSRC=			${WRKDIR}/memmgr-1.04
CATEGORIES=		devel
MASTER_SITES=		http://www.snake.net/software/MemMgr/

MAINTAINER=		collver1@comcast.net
HOMEPAGE=		${MASTER_SITES}
COMMENT=		Simple memory manager library

BUILD_DEPENDS+=		libetm-1.09:../../devel/libetm

post-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.bak
	${SED} <${WRKSRC}/Makefile.bak >${WRKSRC}/Makefile \
		-e 's|/usr/local|${PREFIX}|' \
		-e 's|/usr/ucb/install|${INSTALL}|'

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libmemmgr
	groff -Tascii -ms ${WRKSRC}/memmgr.ms \
		>${PREFIX}/share/doc/libmemmgr/memmgr.txt

.include "../../mk/bsd.pkg.mk"
