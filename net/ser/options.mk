# $NetBSD: options.mk,v 1.1 2007/06/01 00:26:36 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ser
PKG_SUPPORTED_OPTIONS=	mysql

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmysql)
MAKE_ENV+= include_modules="mysql"
.include "../../mk/mysql.buildlink3.mk"
PLIST_SUBST+=	WITH_MYSQL=""
.else
PLIST_SUBST+=	WITH_MYSQL="@comment "
.endif
