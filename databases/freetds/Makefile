# $NetBSD: Makefile,v 1.17 2003/10/09 17:23:16 jdolecek Exp $

DISTNAME=	freetds-0.61.2
CATEGORIES=	databases
MASTER_SITES=	ftp://ftp.ibiblio.org/pub/Linux/ALPHA/freetds/stable/

MAINTAINER=	tsarna@NetBSD.org
HOMEPAGE=	http://www.freetds.org/
COMMENT=	LGPL'd implementation of Sybase's db-lib/ct-lib/ODBC libs

USE_BUILDLINK2=		yes
USE_PKGINSTALL=		yes
USE_GMAKE=		yes

GNU_CONFIGURE=		yes
GNU_CONFIGURE_PREFIX=	${PREFIX}/freetds
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-libiconv-prefix=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--with-tdsver=7.0

USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

EGDIR=		${PREFIX}/share/examples/freetds
CONF_FILES=	${EGDIR}/freetds.conf ${PKG_SYSCONFDIR}/freetds.conf
CONF_FILES+=	${EGDIR}/locales.conf ${PKG_SYSCONFDIR}/locales.conf
CONF_FILES+=	${EGDIR}/pool.conf ${PKG_SYSCONFDIR}/pool.conf

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/freetds.conf ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/locales.conf ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/src/pool/pool.conf ${EGDIR}

.include "../../converters/libiconv/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
