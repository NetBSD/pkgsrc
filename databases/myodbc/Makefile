# $NetBSD: Makefile,v 1.1.1.1 2001/04/04 12:58:43 agc Exp $
#

DISTNAME=		MyODBC-2.50.36
PKGNAME=		myodbc-2.50.36
CATEGORIES=		databases
MASTER_SITES=		http://www.mysql.com/Downloads/MyODBC/

MAINTAINER=		packages@netbsd.org
HOMEPAGE=		http://www.mysql.com/
COMMENT=		ODBC driver (server side) for MySQL

DEPENDS+=		mysql-client>=3.23.35:../../databases/mysql-client
DEPENDS+=		iodbc-*:../../databases/iodbc

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--with-mysql-libs=${LOCALBASE}/lib/mysql
CONFIGURE_ARGS+=	--with-mysql-includes=${LOCALBASE}/include/mysql
CONFIGURE_ARGS+=	--with-iodbc=${LOCALBASE}
CONFIGURE_ARGS+=	--with-odbc-ini=${LOCALBASE}/etc/odbc.ini

USE_LIBTOOL=		yes
LTCONFIG_OVERRIDE=	${WRKSRC}/ltconfig

USE_GMAKE=		yes

.include "../../mk/bsd.pkg.mk"
