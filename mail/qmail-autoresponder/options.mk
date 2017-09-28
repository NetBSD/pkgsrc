# $NetBSD: options.mk,v 1.1 2017/09/28 17:27:34 schmonz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.qmail-autoresponder
PKG_SUPPORTED_OPTIONS+=		mysql

.include "../../mk/bsd.options.mk"

PLIST_VARS+=			mysql
.if !empty(PKG_OPTIONS:Mmysql)
.  include "../../mk/mysql.buildlink3.mk"
BUILD_TARGET+=			mysql
PLIST.mysql=			yes
.endif
