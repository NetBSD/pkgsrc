# $NetBSD: options.mk,v 1.3 2020/01/01 14:16:41 nia Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.im-ja
PKG_SUPPORTED_OPTIONS=	anthy canna wnn4 skk xim
PKG_SUGGESTED_OPTIONS=	anthy canna skk xim

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		xim

#
# Canna support
#
.if !empty(PKG_OPTIONS:Mcanna)
.include "../../inputmethod/canna-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-canna
.endif

#
# Anthy support
#
.if !empty(PKG_OPTIONS:Manthy)
.include "../../inputmethod/anthy/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-anthy
.endif

#
# Wnn support
#
.if !empty(PKG_OPTIONS:Mwnn4)
.include "../../inputmethod/ja-freewnn-lib/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-wnn
.endif

#
# SKK support
#
.if empty(PKG_OPTIONS:Mskk)
CONFIGURE_ARGS+=	--disable-skk
.endif

#
# XIM support
#
.if !empty(PKG_OPTIONS:Mxim)
.include "../../x11/libX11/buildlink3.mk"
PLIST.xim=	yes
.else
CONFIGURE_ARGS+=	--disable-xim
.endif
