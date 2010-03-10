# $NetBSD: Makefile,v 1.1.1.1 2010/03/10 23:55:48 wiz Exp $
#

.include "../../databases/libdbi/Makefile_drivers"

PKGREVISION=		1
LICENSE=		gnu-lgpl-v2

DRIVER=			pgsql

COMMENT=		PostgreSQL driver for libdbi, a database abstraction

CONFLICTS=		libdbi-pgsql-[0-9]*

CONFIGURE_ARGS+=	--with-pgsql
CONFIGURE_ARGS+=	--with-pgsql-incdir=${BUILDLINK_PREFIX.postgresql82-client}/include
CONFIGURE_ARGS+=	--with-pgsql-libdir=${BUILDLINK_PREFIX.postgresql82-client}/lib

.include "../../databases/libdbi/buildlink3.mk"
.include "../../databases/postgresql82-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
