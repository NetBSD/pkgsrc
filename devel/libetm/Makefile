# $NetBSD: Makefile,v 1.2 2002/12/24 18:55:37 wiz Exp $
#

DISTNAME=		ETM-1.09
PKGNAME=		libetm-1.09
CATEGORIES=		devel
MASTER_SITES=		http://www.primate.wisc.edu/software/ETM/

MAINTAINER=		collver1@attbi.com
HOMEPAGE=		http://www.primate.wisc.edu/software/ETM/
COMMENT=		exception and termination manager

WRKSRC=			${WRKDIR}/etm

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
