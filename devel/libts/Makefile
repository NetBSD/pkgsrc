# $NetBSD: Makefile,v 1.5 2003/07/21 16:43:32 martti Exp $
#

DISTNAME=		TS-1.08
PKGNAME=		libts-1.08
WRKSRC=			${WRKDIR}/tokenscan
CATEGORIES=		devel
MASTER_SITES=		http://www.primate.wisc.edu/software/TS/

MAINTAINER=		collver1@comcast.net
HOMEPAGE=		http://www.primate.wisc.edu/software/TS/
COMMENT=		Library of simple token-scanning routines

post-patch:
	${MV} ${WRKSRC}/Makefile ${WRKSRC}/Makefile.bak
	${SED} <${WRKSRC}/Makefile.bak >${WRKSRC}/Makefile \
		-e "s|/usr/local|${PREFIX}|" \
		-e "s|install.sh|${INSTALL}|"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/libts
	groff -Tascii -ms ${WRKSRC}/tokenscan.ms \
		>${PREFIX}/share/doc/libts/tokenscan.txt

.include "../../mk/bsd.pkg.mk"
