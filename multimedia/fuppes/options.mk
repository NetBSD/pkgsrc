# $NetBSD: options.mk,v 1.3 2011/06/23 09:50:25 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.fuppes
PKG_SUPPORTED_OPTIONS=	mpeg4ip mysql
PKG_SUGGESTED_OPTIONS=	mpeg4ip

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		${PKG_SUPPORTED_OPTIONS}

.if !empty(PKG_OPTIONS:Mmpeg4ip)
.include "../../multimedia/mpeg4ip/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmysql)
PLIST.mysql=		yes
.include "../../mk/mysql.buildlink3.mk"
.else
CONFIGURE_ENV+=		ac_cv_path_MYSQL_CONFIG=no
.endif
