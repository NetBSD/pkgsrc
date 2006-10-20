# $NetBSD: options.mk,v 1.1.1.1 2006/10/20 22:40:24 adrianp Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.anope
PKG_SUPPORTED_OPTIONS=	mysql anope-dbencryption

.include "../../mk/bsd.options.mk"

###
### Use MySQL for storing data
###
.if !empty(PKG_OPTIONS:Mmysql)
.	include "../../mk/mysql.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-mysql
.endif

###
### Encrypt sensitive data in the database (only with mysql)
###
.if !empty(PKG_OPTIONS:Mmysql) && !empty(PKG_OPTIONS:Manope-dbencryption)
CONFIGURE_ARGS+=	--with-encryption
.endif
