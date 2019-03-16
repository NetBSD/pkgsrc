# $NetBSD: Makefile,v 1.23 2019/03/16 14:06:22 rillig Exp $
#

PKGREVISION= 7
.include "../../databases/libdbi-driver-sqlite3/driver.mk"

LICENSE=		gnu-lgpl-v2.1

DRIVER=			sqlite3

COMMENT=		SQLite3 driver for libdbi, a database abstraction

CONFLICTS=		libdbi-sqlite3-[0-9]*

CONFIGURE_ARGS+=	--with-sqlite3
CONFIGURE_ARGS+=	--with-sqlite3-incdir=${BUILDLINK_PREFIX.sqlite}/include
CONFIGURE_ARGS+=	--with-sqlite3-libdir=${BUILDLINK_PREFIX.sqlite}/lib

.include "../../databases/libdbi/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
