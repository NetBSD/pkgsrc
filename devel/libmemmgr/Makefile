# $NetBSD: Makefile,v 1.1.1.1 2001/04/27 12:10:40 agc Exp $
#

DISTNAME=		MemMgr-1.04
PKGNAME=		libmemmgr-1.04
CATEGORIES=		devel
MASTER_SITES=		http://www.primate.wisc.edu/software/MemMgr/

MAINTAINER=		collver@linuxfreemail.com
HOMEPAGE=		http://www.primate.wisc.edu/software/MemMgr/
COMMENT=		simple memory manager library

BUILD_DEPENDS+=		libetm-1.09:../../devel/libetm

WRKSRC=			${WRKDIR}/memmgr-1.04

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
