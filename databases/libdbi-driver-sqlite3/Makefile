# $NetBSD: Makefile,v 1.37 2024/11/14 22:19:00 wiz Exp $
#

PKGREVISION= 21
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
