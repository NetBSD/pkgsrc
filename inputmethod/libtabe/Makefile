# $NetBSD: Makefile,v 1.6 2003/07/21 16:52:29 martti Exp $
#

DISTNAME=	libtabe-0.2.5
WRKSRC=		${WRKDIR}/libtabe
CATEGORIES=	chinese inputmethod
MASTER_SITES=	ftp://xcin.linux.org.tw/pub/xcin/libtabe/devel/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://libtabe.sourceforge.net/
COMMENT=	Library for Chinese language processing

USE_BUILDLINK2=		# defined
USE_X11=		# defined
USE_LIBTOOL=		# defined
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-db-inc=${BUILDLINK_PREFIX.db3}/include/db3
CONFIGURE_ARGS+=	--with-db-lib=${BUILDLINK_PREFIX.db3}/lib

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tabe
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/tabe
	${INSTALL_DATA} ${WRKSRC}/src/supports/bims/README \
		${PREFIX}/share/doc/tabe/README.bims
	${INSTALL_DATA} ${WRKSRC}/tsi-src/README \
		${PREFIX}/share/doc/tabe/README.tsi

.include "../../databases/db3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
