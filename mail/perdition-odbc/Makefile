# $NetBSD: Makefile,v 1.3 2007/09/04 21:16:25 joerg Exp $
#

PKGREVISION=		1

PERDITION_COMMENT=	UnixODBC user database module
PERDITION_PKGNAME=	odbc

CONFIGURE_ARGS+=	--with-odbc-includes=${BUILDLINK_PREFIX.unixodbc}/include
CONFIGURE_ARGS+=	--with-odbc-libs=${BUILDLINK_PREFIX.unixodbc}/lib

USE_TOOLS+=	bash:run
REPLACE_BASH+=	perdition/db/odbc/perditiondb_odbc_makedb

.include "../../databases/unixodbc/buildlink3.mk"
.include "../perdition/Makefile.common"
