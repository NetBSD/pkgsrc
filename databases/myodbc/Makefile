# $NetBSD: Makefile,v 1.8 2004/10/03 00:13:21 tv Exp $
#

DISTNAME=		MyODBC-2.50.36
PKGNAME=		myodbc-2.50.36
PKGREVISION=		1
CATEGORIES=		databases
MASTER_SITES=		http://www.mysql.com/Downloads/MyODBC/

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.mysql.com/
COMMENT=		ODBC driver (server side) for MySQL

DEPENDS+=		mysql-client>=3.23.35:../../databases/mysql-client
DEPENDS+=		iodbc-[0-9]*:../../databases/iodbc

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-mysql-libs=${LOCALBASE}/lib/mysql
CONFIGURE_ARGS+=	--with-mysql-includes=${LOCALBASE}/include/mysql
CONFIGURE_ARGS+=	--with-iodbc=${LOCALBASE}
CONFIGURE_ARGS+=	--with-odbc-ini=${LOCALBASE}/etc/odbc.ini

USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

USE_GNU_TOOLS+=		make

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/myodbc
	${INSTALL_DATA} ${WRKSRC}/INSTALL ${PREFIX}/share/doc/myodbc
	${INSTALL_DATA} ${WRKSRC}/README-WIN32 ${PREFIX}/share/doc/myodbc

.include "../../mk/bsd.pkg.mk"
