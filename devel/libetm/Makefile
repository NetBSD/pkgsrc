# $NetBSD: Makefile,v 1.7 2003/12/11 20:16:10 ben Exp $
#

DISTNAME=		ETM-1.09
PKGNAME=		libetm-1.09
WRKSRC=			${WRKDIR}/etm
CATEGORIES=		devel
MASTER_SITES=		http://www.snake.net/software/ETM/

MAINTAINER=		collver1@comcast.net
HOMEPAGE=		${MASTER_SITES}
COMMENT=		Exception and termination manager

post-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.bak
	${SED} <${WRKSRC}/Makefile.bak >${WRKSRC}/Makefile \
		-e 's|/usr/local|${PREFIX}|' \
		-e 's|install.sh|$${BSD_INSTALL}|'

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libetm
	groff -Tascii -ms ${WRKSRC}/etm.ms \
		>${PREFIX}/share/doc/libetm/etm.txt

.include "../../mk/bsd.pkg.mk"
