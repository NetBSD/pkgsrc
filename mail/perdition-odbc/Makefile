# $NetBSD: Makefile,v 1.7 2011/12/17 19:03:24 marino Exp $

PERDITION_COMMENT=	UnixODBC user database module
PERDITION_PKGNAME=	odbc
PKGREVISION=		1

PKG_DESTDIR_SUPPORT=	user-destdir

CONFIGURE_ARGS+=	--with-odbc-includes=${BUILDLINK_PREFIX.unixodbc}/include
CONFIGURE_ARGS+=	--with-odbc-libs=${BUILDLINK_PREFIX.unixodbc}/lib

USE_TOOLS+=	bash:run
REPLACE_BASH+=	perdition/db/odbc/perditiondb_odbc_makedb

.include "../../databases/unixodbc/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../mail/perdition/Makefile.common"
