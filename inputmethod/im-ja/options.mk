# $NetBSD: options.mk,v 1.2 2012/03/10 15:24:50 obache Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.im-ja
PKG_SUPPORTED_OPTIONS=	anthy canna wnn4 skk gnome xim
PKG_SUGGESTED_OPTIONS=	anthy canna skk gnome xim

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		gnome xim

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
# Gnome applet
#
.if !empty(PKG_OPTIONS:Mgnome)
.include "../../x11/gnome-panel/buildlink3.mk"
PLIST.gnome=	yes
.else
CONFIGURE_ARGS+=	--disable-gnome
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
