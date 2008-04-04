# $NetBSD: options.mk,v 1.1.1.1 2008/04/04 15:15:50 jlam Exp $

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
CONFIGURE_ARGS+=	--with-odbc-dir=${BUILDLINK_PREFIX.iodbc}
.endif

###
### unixODBC
###
.if !empty(PKG_OPTIONS:Munixodbc)
.  include "../../databases/unixodbc/buildlink3.mk"
CONFIGURE_ARGS+=	--with-odbc-dir=${BUILDLINK_PREFIX.unixodbc}
.endif
