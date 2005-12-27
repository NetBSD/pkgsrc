# $NetBSD: Makefile,v 1.28 2005/12/27 21:04:23 reed Exp $

DISTNAME=	freetds-0.63
PKGREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.ibiblio.org/pub/Linux/ALPHA/freetds/stable/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.freetds.org/
COMMENT=	LGPL'd implementation of Sybase's db-lib/ct-lib/ODBC libs

USE_LIBTOOL=		yes
USE_PKGINSTALL=		yes
USE_TOOLS+=		gmake

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--with-tdsver=7.0

# no thread-safe resolver functions on NetBSD
CONFIGURE_ARGS+=	--disable-threadsafe

EGDIR=		${PREFIX}/share/examples/freetds
CONF_FILES=	${EGDIR}/freetds.conf ${PKG_SYSCONFDIR}/freetds.conf
CONF_FILES+=	${EGDIR}/locales.conf ${PKG_SYSCONFDIR}/locales.conf
CONF_FILES+=	${EGDIR}/pool.conf ${PKG_SYSCONFDIR}/pool.conf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/freetds.conf ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/locales.conf ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/src/pool/pool.conf ${EGDIR}

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
