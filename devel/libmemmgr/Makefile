# $NetBSD: Makefile,v 1.3 2003/03/29 12:40:34 jmmv Exp $
#

DISTNAME=		MemMgr-1.04
PKGNAME=		libmemmgr-1.04
WRKSRC=			${WRKDIR}/memmgr-1.04
CATEGORIES=		devel
MASTER_SITES=		http://www.primate.wisc.edu/software/MemMgr/

MAINTAINER=		collver1@attbi.com
HOMEPAGE=		http://www.primate.wisc.edu/software/MemMgr/
COMMENT=		simple memory manager library

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
