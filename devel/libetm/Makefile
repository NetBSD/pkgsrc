# $NetBSD: Makefile,v 1.3 2003/03/29 12:40:34 jmmv Exp $
#

DISTNAME=		ETM-1.09
PKGNAME=		libetm-1.09
WRKSRC=			${WRKDIR}/etm
CATEGORIES=		devel
MASTER_SITES=		http://www.primate.wisc.edu/software/ETM/

MAINTAINER=		collver1@attbi.com
HOMEPAGE=		http://www.primate.wisc.edu/software/ETM/
COMMENT=		exception and termination manager

post-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.bak
	${SED} <${WRKSRC}/Makefile.bak >${WRKSRC}/Makefile \
		-e 's|/usr/local|${PREFIX}|' \
		-e 's|install.sh|${INSTALL}|'

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libetm
	groff -Tascii -ms ${WRKSRC}/etm.ms \
		>${PREFIX}/share/doc/libetm/etm.txt

.include "../../mk/bsd.pkg.mk"
