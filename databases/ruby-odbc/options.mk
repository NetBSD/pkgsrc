# $NetBSD: options.mk,v 1.2 2012/04/07 04:47:27 obache Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.ruby-odbc
PKG_OPTIONS_REQUIRED_GROUPS=	odbc
PKG_OPTIONS_GROUP.odbc=		iodbc unixodbc
PKG_SUGGESTED_OPTIONS=		iodbc

.include "../../mk/bsd.options.mk"

###
### iODBC
###
.if !empty(PKG_OPTIONS:Miodbc)
.  include "../../databases/iodbc/buildlink3.mk"
CONFIGURE_ARGS+=	--with-odbc-include=${BUILDLINK_PREFIX.iodbc}/include/iodbc
CONFIGURE_ARGS+=	--with-odbc-lib=${BUILDLINK_PREFIX.iodbc}/lib/iodbc
.endif

###
### unixODBC
###
.if !empty(PKG_OPTIONS:Munixodbc)
.  include "../../databases/unixodbc/buildlink3.mk"
CONFIGURE_ARGS+=	--with-odbc-dir=${BUILDLINK_PREFIX.unixodbc}
.endif
