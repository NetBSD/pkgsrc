# $NetBSD: Makefile,v 1.3 2016/08/21 19:16:58 fhajny Exp $
#

.include "../../databases/libdbi-driver-sqlite3/Makefile_drivers"

LICENSE=		gnu-lgpl-v2.1

DRIVER=			sqlite

COMMENT=		SQLite driver for libdbi, a database abstraction

CONFLICTS=		libdbi-sqlite-[0-9]*

CONFIGURE_ARGS+=	--with-sqlite
CONFIGURE_ARGS+=	--with-sqlite-incdir=${BUILDLINK_PREFIX.sqlite}/include
CONFIGURE_ARGS+=	--with-sqlite-libdir=${BUILDLINK_PREFIX.sqlite}/lib

.include "../../databases/libdbi/buildlink3.mk"
.include "../../databases/sqlite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
