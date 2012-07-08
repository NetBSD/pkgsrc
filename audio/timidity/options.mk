# $NetBSD: options.mk,v 1.1 2012/07/08 09:52:05 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.timidity
PKG_SUPPORTED_OPTIONS=	x11 gtk
PKG_SUGGESTED_OPTIONS=	x11 gtk

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	x11

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--enable-spectrogram
CONFIGURE_ARGS+=	--enable-wrd
# For wrd
.include "../../graphics/png/buildlink3.mk"

PLIST.x11=	yes

.include "../../mk/bsd.prefs.mk"

.if !defined(XAW_TYPE)
WITH_XAWLIB=--with-xawlib=xaw,xaw3d,neXtaw
.elif ${XAW_TYPE} == "standard"
WITH_XAWLIB=--with-xawlib=xaw,xaw3d,neXtaw
.elif ${XAW_TYPE} == "3d"
WITH_XAWLIB=--with-xawlib=xaw3d
.elif ${XAW_TYPE} == "xpm"
WITH_XAWLIB=--with-xawlib=xaw3d
.elif ${XAW_TYPE} == "neXtaw"
WITH_XAWLIB=--with-xawlib=neXtaw
.endif

CONFIGURE_ARGS+=	--enable-xaw --enable-xdnd --with-xaw-resource-prefix="${PREFIX}/lib/X11/" ${WITH_XAWLIB}
#CONFIGURE_ARGS+=	--enable-xft

.include "../../mk/xaw.buildlink3.mk"
#.include "../../x11/libXft/buildlink3.mk"

.if !empty(PKG_OPTIONS:Mgtk)
CONFIGURE_ARGS+=	--enable-gtk
.include "../../x11/gtk2/buildlink3.mk"
.endif

.else
CONFIGURE_ARGS+=	--without-x
.endif
