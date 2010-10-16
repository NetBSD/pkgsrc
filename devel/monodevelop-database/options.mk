# $NetBSD: options.mk,v 1.1.1.1 2010/10/16 21:40:29 kefren Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.monodevelop-database
PKG_SUPPORTED_OPTIONS=	mysql
PKG_SUGGESTED_OPTIONS=	mysql

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmysql)
.include "../../databases/csharp-mysql/buildlink3.mk"
.endif
