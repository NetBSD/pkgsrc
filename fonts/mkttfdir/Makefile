# $NetBSD: Makefile,v 1.1.1.1 2001/06/29 18:15:30 wiz Exp $
#

DISTNAME=	mkttfdir-1.0
CATEGORIES=	fonts
MASTER_SITES=	http://members.tripodasia.com.tw/rxg/

MAINTAINER=	rxg@ms25.url.com.tw
COMMENT=	create an index of X TrueType fonts files in a directory

pre-build:
	${SED} -e 's|prefix|${PREFIX}|g' ${WRKSRC}/mkttfdir > ${WRKSRC}/mkttfdir.tmp
	${MV} -f ${WRKSRC}/mkttfdir.tmp ${WRKSRC}/mkttfdir

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttfinfo ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mkttfdir ${PREFIX}/bin

.include "../../graphics/freetype-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
