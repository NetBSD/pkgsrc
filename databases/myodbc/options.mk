# $NetBSD: options.mk,v 1.9 2024/08/25 06:18:30 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.myodbc
PKG_OPTIONS_REQUIRED_GROUPS=	db
PKG_OPTIONS_GROUP.db=		iodbc unixodbc
PKG_SUGGESTED_OPTIONS=		iodbc

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Miodbc)
.  include "../../databases/iodbc/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Munixodbc)
.  include "../../databases/unixodbc/buildlink3.mk"
CMAKE_CONFIGURE_ARGS+=		-DWITH_UNIXODBC=1
.endif
