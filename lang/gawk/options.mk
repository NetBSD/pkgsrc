# $NetBSD: options.mk,v 1.4 2024/05/01 20:02:14 cheusov Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gawk
PKG_SUPPORTED_OPTIONS=	portals readline nls
PKG_SUGGESTED_OPTIONS=	readline nls

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		nls

.if !empty(PKG_OPTIONS:Mportals)
CONFIGURE_ARGS+=	--enable-portals
.endif

.if !empty(PKG_OPTIONS:Mreadline)
.include "../../devel/readline/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-readline
.endif

# nls
.if !empty(PKG_OPTIONS:Mnls)
.include "../../devel/gettext-lib/buildlink3.mk"
PLIST.nls=	yes
.else
CONFIGURE_ARGS+= --disable-nls
.endif
