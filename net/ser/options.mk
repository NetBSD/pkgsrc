# $NetBSD: options.mk,v 1.2 2008/04/12 22:43:08 jlam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ser
PKG_SUPPORTED_OPTIONS=	mysql

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	mysql
.if !empty(PKG_OPTIONS:Mmysql)
MAKE_ENV+= include_modules="mysql"
.include "../../mk/mysql.buildlink3.mk"
PLIST.mysql=	yes
.endif
