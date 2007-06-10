# $NetBSD: options.mk,v 1.3 2007/06/10 22:20:10 tonio Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.weechat
PKG_SUPPORTED_OPTIONS=	charset gnutls python lua
PKG_SUGGESTED_OPTIONS=	charset

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcharset)
CONFIGURE_ARGS+=	--enable-charset
PLIST_SUBST+= WITHCHARSET=""
.else
CONFIGURE_ARGS+=	--disable-charset
PLIST_SUBST+= WITHCHARSET="@comment "
.endif

.if !empty(PKG_OPTIONS:Mgnutls)
.include "../../security/gnutls/buildlink3.mk"
.endif

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

.if !empty(PKG_OPTIONS:Mpython) || !empty(PKG_OPTIONS:Mlua) \
    || !empty(PKG_OPTIONS:Mcharset)
PLIST_SUBST+= WITHPLUGIN=""
.else
PLIST_SUBST+= WITHPLUGIN="@comment "
.endif
