# $NetBSD: options.mk,v 1.1 2006/10/02 21:02:03 tonio Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.weechat
PKG_SUPPORTED_OPTIONS=	python lua

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mpython)
.include "../../lang/python/extension.mk"
CONFIGURE_ARGS+=	--enable-python
PLIST_SUBST+= WITHPYTHON=""
.else
CONFIGURE_ARGS+=	--disable-python
PLIST_SUBST+= WITHPYTHON="@comment "
.endif

.if !empty(PKG_OPTIONS:Mlua)
.include "../../lang/lua/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-lua
PLIST_SUBST+= WITHLUA=""
.else
CONFIGURE_ARGS+=	--disable-lua
PLIST_SUBST+= WITHLUA="@comment "
.endif

.if !empty(PKG_OPTIONS:Mpython) || !empty(PKG_OPTIONS:Mlua)
PLIST_SUBST+= WITHPLUGIN=""
.else
PLIST_SUBST+= WITHPLUGIN="@comment "
.endif
