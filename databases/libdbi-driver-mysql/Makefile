# $NetBSD: Makefile,v 1.6 2016/08/21 19:16:57 fhajny Exp $
#

.include "../../databases/libdbi-driver-sqlite3/Makefile_drivers"

LICENSE=		gnu-lgpl-v2.1

DRIVER=			mysql

COMMENT=		MySQL driver for libdbi, a database abstraction

CONFLICTS=		libdbi-mysql-[0-9]*

CONFIGURE_ARGS+=	--with-mysql
CONFIGURE_ARGS+=	--with-mysql-incdir=${BUILDLINK_PREFIX.mysql-client}/include
CONFIGURE_ARGS+=	--with-mysql-libdir=${BUILDLINK_PREFIX.mysql-client}/lib

.include "../../databases/libdbi/buildlink3.mk"
.include "../../mk/mysql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
