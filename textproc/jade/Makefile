# $NetBSD: Makefile,v 1.2 1999/03/15 08:48:15 rh Exp $
# FreeBSD Id: Makefile,v 1.15 1999/01/31 11:15:57 dirk Exp
#

DISTNAME=	jade-1.2.1
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.jclark.com/pub/jade/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.jclark.com/pub/jade/ \
		ftp://ftp.uni-trier.de/pub/languages/sgml/jade/ \
		ftp://ftp.u-aizu.ac.jp/pub/lang/sgml/jade/

MAINTAINER=	rh@NetBSD.ORG
HOMEPAGE=	http://www.jclark.com/jade/

CONFLICTS+=	sp-*

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CXXFLAGS="${CFLAGS}"
CONFIGURE_ARGS=	--disable-shared

post-install:
.for i in jade nsgmls sgmlnorm spam spent sx
	strip ${PREFIX}/bin/$i
.endfor
	${MKDIR} ${PREFIX}/include/sp
	${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/include/sp
	${MKDIR} ${PREFIX}/share/doc/jade
	${INSTALL_DATA} ${WRKSRC}/doc/*.htm ${PREFIX}/share/doc/jade
	${MKDIR} ${PREFIX}/share/sgml/jade
	${INSTALL_DATA} ${WRKSRC}/dsssl/* ${PREFIX}/share/sgml/jade

.include "../../mk/bsd.pkg.mk"
