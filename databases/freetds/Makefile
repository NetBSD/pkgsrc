# $NetBSD: Makefile,v 1.10 2002/09/20 00:08:34 grant Exp $

DISTNAME=	freetds-0.53
CATEGORIES=	databases
PKGREVISION=	1
MASTER_SITES=	ftp://ftp.metalab.unc.edu/pub/Linux/ALPHA/freetds/
EXTRACT_SUFX=	.tgz

MAINTAINER=	tsarna@netbsd.org
HOMEPAGE=	http://www.freetds.org/
COMMENT=	LGPL'd implementation of Sybase's db-lib/ct-lib/ODBC libs

USE_BUILDLINK2=		yes
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

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/freetds.conf ${EGDIR}

.include "../../converters/libiconv/buildlink2.mk"
.include "../../mk/bsd.pkg.install.mk"
.include "../../mk/bsd.pkg.mk"
