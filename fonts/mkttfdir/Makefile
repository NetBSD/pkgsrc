# $NetBSD: Makefile,v 1.2 2001/11/22 13:42:08 agc Exp $
#

DISTNAME=	mkttfdir-1.1
CATEGORIES=	fonts
MASTER_SITES=	http://residence.educities.edu.tw/rxghome/

MAINTAINER=	rxg@ms25.url.com.tw
COMMENT=	create an index of X TrueType fonts files in a directory

MAKE_FLAGS+=	prefix=${PREFIX} FREETYPE_BASE=${LOCALBASE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttfinfo ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/mkttfdir ${PREFIX}/bin

.include "../../graphics/freetype-lib/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
