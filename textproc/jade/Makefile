# $NetBSD: Makefile,v 1.10 2001/04/23 15:37:38 skrll Exp $
# FreeBSD Id: Makefile,v 1.15 1999/01/31 11:15:57 dirk Exp
#

DISTNAME=	jade-1.2.1
PKGNAME=	jade-1.2.1nb2
CATEGORIES=	textproc
MASTER_SITES=	ftp://ftp.jclark.com/pub/jade/ \
		ftp://ftp.funet.fi/pub/mirrors/ftp.jclark.com/pub/jade/ \
		ftp://ftp.uni-trier.de/pub/languages/sgml/jade/ \
		ftp://ftp.u-aizu.ac.jp/pub/lang/sgml/jade/

MAINTAINER=	rh@NetBSD.ORG
HOMEPAGE=	http://www.jclark.com/jade/
COMMENT=	Object-oriented SGML/XML parser toolkit and DSSSL engine

CONFLICTS+=	sp-*

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE= \
		${WRKSRC}/config/ltconfig

CONFIGURE_ENV+=	CXXFLAGS="${CFLAGS}"
CONFIGURE_ARGS=	--disable-shared
CONFIGURE_ARGS+= --enable-default-catalog=${PREFIX}/share/sgml/jade/catalog
CONFIGURE_ARGS+= --enable-mif

post-install:
.for i in jade nsgmls sgmlnorm spam spent sx
	strip ${PREFIX}/bin/$i
.endfor
	${INSTALL_DATA_DIR} ${PREFIX}/include/sp
	${INSTALL_DATA} ${WRKSRC}/include/* ${PREFIX}/include/sp
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/jade
	${INSTALL_DATA} ${WRKSRC}/jadedoc/*.htm ${PREFIX}/share/doc/jade
	${INSTALL_DATA_DIR} ${PREFIX}/share/sgml/jade
	${INSTALL_DATA} ${WRKSRC}/dsssl/* ${PREFIX}/share/sgml/jade

.include "../../mk/bsd.pkg.mk"
