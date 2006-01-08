# $NetBSD: Makefile,v 1.12 2006/01/08 18:35:08 xtraeme Exp $
#

DISTNAME=		MyODBC-2.50.36
PKGNAME=		myodbc-2.50.36
PKGREVISION=		2
CATEGORIES=		databases
MASTER_SITES=		http://www.mysql.com/Downloads/MyODBC/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.mysql.com/
COMMENT=		ODBC driver (server side) for MySQL

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-mysql-libs=${BUILDLINK_PREFIX.mysql-client}/lib/mysql
CONFIGURE_ARGS+=	--with-mysql-includes=${BUILDLINK_PREFIX.mysql-client}/include/mysql
CONFIGURE_ARGS+=	--with-iodbc=${BUILDLINK_PREFIX.iodbc}
CONFIGURE_ARGS+=	--with-odbc-ini=${BUILDLINK_PREFIX.iodbc}/etc/odbc.ini

USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

USE_TOOLS+=		gmake

.include "../../databases/iodbc/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/myodbc
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/myodbc
	${INSTALL_DATA} ${WRKSRC}/README-WIN32 ${PREFIX}/share/doc/myodbc

.include "../../mk/bsd.pkg.mk"
