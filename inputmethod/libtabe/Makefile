# $NetBSD: Makefile,v 1.3 2002/09/23 03:00:01 jlam Exp $
#

DISTNAME=	libtabe-0.2.5
CATEGORIES=	chinese inputmethod
MASTER_SITES=	ftp://xcin.linux.org.tw/pub/xcin/libtabe/devel/

MAINTAINER=	rxg@netbsd.org
HOMEPAGE=	http://libtabe.sourceforge.net/
COMMENT=	library for Chinese language processing

USE_BUILDLINK2=		# defined
USE_X11=		# defined
USE_LIBTOOL=		# defined
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

GNU_CONFIGURE=		# defined
CONFIGURE_ARGS+=	--with-db-inc=${BUILDLINK_PREFIX.db3}/include/db3
CONFIGURE_ARGS+=	--with-db-lib=${BUILDLINK_PREFIX.db3}/lib

WRKSRC=		${WRKDIR}/libtabe

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tabe
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/tabe
	${INSTALL_DATA} ${WRKSRC}/src/supports/bims/README \
		${PREFIX}/share/doc/tabe/README.bims
	${INSTALL_DATA} ${WRKSRC}/tsi-src/README \
		${PREFIX}/share/doc/tabe/README.tsi

.include "../../databases/db3/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
