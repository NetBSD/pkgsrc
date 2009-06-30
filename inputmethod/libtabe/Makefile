# $NetBSD: Makefile,v 1.17 2009/06/30 00:07:17 joerg Exp $
#

DISTNAME=	libtabe-0.2.5
PKGREVISION=	2
CATEGORIES=	chinese inputmethod
MASTER_SITES=	ftp://xcin.linux.org.tw/pub/xcin/libtabe/devel/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://libtabe.sourceforge.net/
COMMENT=	Library for Chinese language processing

MAKE_JOBS_SAFE=		no

WRKSRC=			${WRKDIR}/libtabe
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-db-inc=${BUILDLINK_PREFIX.db3}/include/db3
CONFIGURE_ARGS+=	--with-db-lib=${BUILDLINK_PREFIX.db3}/lib

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/tabe
	${INSTALL_DATA} ${WRKSRC}/doc/* ${PREFIX}/share/doc/tabe
	${INSTALL_DATA} ${WRKSRC}/src/supports/bims/README \
		${PREFIX}/share/doc/tabe/README.bims
	${INSTALL_DATA} ${WRKSRC}/tsi-src/README \
		${PREFIX}/share/doc/tabe/README.tsi

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../databases/db3/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
