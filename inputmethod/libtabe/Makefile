# $NetBSD: Makefile,v 1.1.1.1 2002/06/04 08:31:10 uebayasi Exp $
#

DISTNAME=	libtabe-0.2.5
CATEGORIES=	chinese inputmethod
MASTER_SITES=	ftp://xcin.linux.org.tw/pub/xcin/libtabe/devel/

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://libtabe.sourceforge.net/
COMMENT=	library for Chinese language processing

USE_LIBTOOL=	yes
LTCONFIG_OVERRIDE=	${WRKSRC}/script/ltmain.sh
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-db-inc=${LOCALBASE}/include/db3 \
		--with-db-lib=${LOCALBASE}/lib

WRKSRC=		${WRKDIR}/libtabe

post-configure:
	# this pkg generates libtool script from configure file
	cd ${WRKSRC} && script/ltmain.sh

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tabe
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/tabe
	${INSTALL_DATA} ${WRKSRC}/src/supports/bims/README \
		${PREFIX}/share/doc/tabe/README.bims
	${INSTALL_DATA} ${WRKSRC}/tsi-src/README \
		${PREFIX}/share/doc/tabe/README.tsi

.include "../../databases/db3/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
