# $NetBSD: options.mk,v 1.1 2021/07/02 15:21:12 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.php-pdo_mysql
PKG_SUPPORTED_OPTIONS=	mysqlnd
PKG_SUGGESTED_OPTIONS=	# empty

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmysqlnd)
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,mysqlnd
.else
CONFIGURE_ARGS+=	--with-${MODNAME}=shared,${BUILDLINK_PREFIX.mysql-client}
.include "../../mk/mysql.buildlink3.mk"
.endif
