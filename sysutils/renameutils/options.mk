# $NetBSD: options.mk,v 1.1 2018/11/09 12:50:49 bsiegert Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.renameutils
PKG_SUPPORTED_OPTIONS=	nls
PKG_SUGGESTED_OPTIONS=	nls

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		nls

.if !empty(PKG_OPTIONS:Mnls)
USE_PKGLOCALEDIR=       yes
PLIST.nls=		yes
.include "../../devel/gettext-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-nls
.endif
