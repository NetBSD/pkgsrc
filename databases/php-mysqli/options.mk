# $NetBSD: options.mk,v 1.1 2021/07/02 15:18:42 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.php-mysqli
PKG_SUPPORTED_OPTIONS=	mysqlnd
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmysqlnd)
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,mysqlnd
.else
.  include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-${MODNAME}=${BUILDLINK_PREFIX.mysql-client}/bin/mysql_config
.endif
