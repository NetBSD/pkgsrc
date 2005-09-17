# $NetBSD: Makefile,v 1.10 2005/09/17 19:21:29 minskim Exp $
#

DISTNAME=		MyODBC-2.50.36
PKGNAME=		myodbc-2.50.36
PKGREVISION=		1
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
.include "../../databases/mysql-client/buildlink3.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/myodbc
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/myodbc
	${INSTALL_DATA} ${WRKSRC}/README-WIN32 ${PREFIX}/share/doc/myodbc

.include "../../mk/bsd.pkg.mk"
