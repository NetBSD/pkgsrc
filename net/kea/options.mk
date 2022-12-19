# $NetBSD: options.mk,v 1.1 2022/12/19 07:44:50 sekiya Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.kea
PKG_SUPPORTED_OPTIONS+=	botan libyang pgsql mysql
PKG_SUGGESTED_OPTIONS=

PLIST_VARS+=	pgsql mysql

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mbotan)
.  include "../../security/botan2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlibyang)
.  include "../../devel/libyang2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpgsql)
.  include "../../mk/pgsql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-pgsql
PLIST.pgsql=	yes
.endif

.if !empty(PKG_OPTIONS:Mmysql)
.  include "../../mk/mysql.buildlink3.mk"
CONFIGURE_ARGS+=	--with-mysql
PLIST.mysql=	yes
.endif
