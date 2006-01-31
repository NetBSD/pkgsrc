# $NetBSD: Makefile,v 1.1 2006/01/31 21:07:31 tv Exp $
#

PERDITION_COMMENT=	UnixODBC user database module
PERDITION_PKGNAME=	odbc

CONFIGURE_ARGS+=	--with-odbc-includes=${BUILDLINK_PREFIX.unixodbc}/include
CONFIGURE_ARGS+=	--with-odbc-libs=${BUILDLINK_PREFIX.unixodbc}/lib

.include "../../databases/unixodbc/buildlink3.mk"
.include "../perdition/Makefile.common"
