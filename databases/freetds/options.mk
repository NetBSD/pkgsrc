# $NetBSD: options.mk,v 1.2 2008/04/12 22:42:59 jlam Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.freetds
PKG_OPTIONS_OPTIONAL_GROUPS+=	odbc
PKG_OPTIONS_GROUP.odbc=		iodbc #unixodbc

.include "../../mk/bsd.options.mk"

PLIST_VARS+=			odbc

###
### Whether to build with iODBC to enable ODBC access to TDS servers.
###
.if !empty(PKG_OPTIONS:Miodbc)
ODBC_DRIVER=		yes
.  include "../../databases/iodbc/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-odbc
CONFIGURE_ARGS+=	--with-iodbc=${BUILDLINK_PREFIX.iodbc}
PLIST.odbc=		yes
.endif

###
### Whether to build with unixODBC to enable ODBC access to TDS servers.
###
.if !empty(PKG_OPTIONS:Munixodbc)
.  include "../../databases/unixodbc/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-odbc
CONFIGURE_ARGS+=	--with-unixodbc=${BUILDLINK_PREFIX.unixodbc}
PLIST.odbc=		yes
.endif

.if empty(PKG_OPTIONS:Miodbc) && empty(PKG_OPTIONS:Munixodbc)
CONFIGURE_ARGS+=	--disable-odbc
.endif
