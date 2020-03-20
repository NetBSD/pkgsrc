# $NetBSD: Makefile,v 1.26 2020/03/20 11:57:54 nia Exp $

DISTNAME=	libtabe-0.2.6
PKGREVISION=	3
CATEGORIES=	chinese inputmethod
MASTER_SITES=	ftp://cle.linux.org.tw/pub/xcin/cvs/

MAINTAINER=	rxg@NetBSD.org
HOMEPAGE=	http://libtabe.sourceforge.net/
COMMENT=	Library for Chinese language processing
LICENSE=	modified-bsd

MAKE_JOBS_SAFE=		no

BDB_ACCEPTED=		db2 db3 db4 db5
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-db-inc=${BDBBASE}/include/${BDB_TYPE}
CONFIGURE_ARGS+=	--with-db-lib=${BDBBASE}/lib
CONFIGURE_ARGS+=	--with-db-name=${BDB_TYPE}

INSTALL_MAKE_FLAGS+=	program_prefix=${DESTDIR}

INSTALLATION_DIRS+=	share/doc/tabe

post-install:
	${INSTALL_DATA} ${WRKSRC}/doc/* ${DESTDIR}${PREFIX}/share/doc/tabe
	${INSTALL_DATA} ${WRKSRC}/src/supports/bims/README \
		${DESTDIR}${PREFIX}/share/doc/tabe/README.bims
	${INSTALL_DATA} ${WRKSRC}/tsi-src/README \
		${DESTDIR}${PREFIX}/share/doc/tabe/README.tsi

BUILDLINK_DEPMETHOD.libXt?=	build

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "modular"
CONFIGURE_ARGS+=	--x-includes=${PREFIX}/include
.endif

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXt/buildlink3.mk"
.include "../../mk/bdb.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
