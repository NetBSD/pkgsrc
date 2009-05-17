# $NetBSD: options.mk,v 1.1.1.1 2009/05/17 13:29:15 sno Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.p5-DBD-ODBC
PKG_OPTIONS_OPTIONAL_GROUPS+=	odbc
PKG_OPTIONS_GROUP.odbc=		iodbc unixodbc
PKG_SUGGESTED_OPTIONS=		unixodbc

.include "../../mk/bsd.options.mk"

###
### Whether to build with iODBC to enable ODBC access to TDS servers.
###
.if !empty(PKG_OPTIONS:Miodbc)
.  include "../../databases/iodbc/buildlink3.mk"
.endif

###
### Whether to build with unixODBC to enable ODBC access to TDS servers.
###
.if !empty(PKG_OPTIONS:Munixodbc)
.  include "../../databases/unixodbc/buildlink3.mk"
.endif
