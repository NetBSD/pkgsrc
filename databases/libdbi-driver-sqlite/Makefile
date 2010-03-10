# $NetBSD: Makefile,v 1.1.1.1 2010/03/10 23:55:48 wiz Exp $
#

.include "../../databases/libdbi/Makefile_drivers"

LICENSE=		gnu-lgpl-v2

DRIVER=			sqlite

COMMENT=		SQLite driver for libdbi, a database abstraction

CONFLICTS=		libdbi-sqlite-[0-9]*

CONFIGURE_ARGS+=	--with-sqlite
CONFIGURE_ARGS+=	--with-sqlite-incdir=${BUILDLINK_PREFIX.sqlite}/include
CONFIGURE_ARGS+=	--with-sqlite-libdir=${BUILDLINK_PREFIX.sqlite}/lib

.include "../../databases/libdbi/buildlink3.mk"
.include "../../databases/sqlite/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
