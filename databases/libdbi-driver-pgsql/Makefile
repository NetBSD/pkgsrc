# $NetBSD: Makefile,v 1.5 2016/08/21 19:16:58 fhajny Exp $
#

.include "../../databases/libdbi-driver-sqlite3/Makefile_drivers"

LICENSE=		gnu-lgpl-v2.1

DRIVER=			pgsql

COMMENT=		PostgreSQL driver for libdbi, a database abstraction

CONFLICTS=		libdbi-pgsql-[0-9]*

CONFIGURE_ARGS+=	--with-pgsql
CONFIGURE_ARGS+=	--with-pgsql-incdir=${PGSQL_PREFIX}/include
CONFIGURE_ARGS+=	--with-pgsql-libdir=${PGSQL_PREFIX}/lib

.include "../../databases/libdbi/buildlink3.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
