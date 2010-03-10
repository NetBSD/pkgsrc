# $NetBSD: Makefile,v 1.1.1.1 2010/03/10 23:55:48 wiz Exp $
#

.include "../../databases/libdbi/Makefile_drivers"

PKGREVISION=		1
LICENSE=		gnu-lgpl-v2

DRIVER=			mysql

COMMENT=		MySQL driver for libdbi, a database abstraction

CONFLICTS=		libdbi-mysql-[0-9]*

CONFIGURE_ARGS+=	--with-mysql
CONFIGURE_ARGS+=	--with-mysql-incdir=${BUILDLINK_PREFIX.mysql-client}/include
CONFIGURE_ARGS+=	--with-mysql-libdir=${BUILDLINK_PREFIX.mysql-client}/lib

.include "../../databases/libdbi/buildlink3.mk"
.include "../../databases/mysql5-client/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
