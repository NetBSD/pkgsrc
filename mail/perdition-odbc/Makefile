# $NetBSD: Makefile,v 1.8 2012/10/08 12:19:26 asau Exp $

PERDITION_COMMENT=	UnixODBC user database module
PERDITION_PKGNAME=	odbc
PKGREVISION=		1

CONFIGURE_ARGS+=	--with-odbc-includes=${BUILDLINK_PREFIX.unixodbc}/include
CONFIGURE_ARGS+=	--with-odbc-libs=${BUILDLINK_PREFIX.unixodbc}/lib

USE_TOOLS+=	bash:run
REPLACE_BASH+=	perdition/db/odbc/perditiondb_odbc_makedb

.include "../../databases/unixodbc/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mail/perdition/Makefile.common"
