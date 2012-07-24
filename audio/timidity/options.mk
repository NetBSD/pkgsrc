# $NetBSD: options.mk,v 1.2 2012/07/24 19:47:43 jperkin Exp $

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

CONFIGURE_ARGS+=	--enable-xaw --enable-xdnd
CONFIGURE_ARGS+=	--with-xaw-resource-prefix="${PREFIX}/lib/X11/"
CONFIGURE_ARGS+=	${WITH_XAWLIB}

# This lets the trace use non-core fonts, but this wouldn't match the core
# font used by Xaw
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
