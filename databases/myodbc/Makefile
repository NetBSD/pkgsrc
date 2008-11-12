# $NetBSD: Makefile,v 1.17.18.1 2008/11/12 07:11:34 rtr Exp $
#

DISTNAME=	mysql-connector-odbc-3.51.26r1127
PKGNAME=	${DISTNAME:S/mysql-connector-odbc/myodbc/}
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_MYSQL:=Connector-ODBC/3.51/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.mysql.com/
COMMENT=	ODBC driver (server side) for MySQL

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

CONFIGURE_ARGS+=	--with-mysql-path=${BUILDLINK_PREFIX.mysql-client}
CONFIGURE_ARGS+=	--datadir=${PREFIX}/share/doc
CONFIGURE_ARGS+=	--disable-gui
CONFIGURE_ARGS+=	--disable-myodbc3i
CONFIGURE_ARGS+=	--without-samples
CONFIGURE_ARGS+=	--disable-test

INSTALLATION_DIRS=	share/doc/mysql-connector-odbc

.include "options.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
