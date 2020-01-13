# $NetBSD: options.mk,v 1.1 2020/01/13 15:46:26 hauke Exp $
#
PKG_OPTIONS_VAR=        PKG_OPTIONS.xboard
PKG_SUPPORTED_OPTIONS=  gtk

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk)
CONFIGURE_ARGS+=	--with-gtk
.include "../../x11/gtk2/buildlink3.mk"

.else

CONFIGURE_ARGS+=	--without-gtk
.include "../../mk/xaw.buildlink3.mk"
BUILD_DEFS+=		XAW_TYPE
.if defined(XAW_TYPE) && (${XAW_TYPE} == "3d" || ${XAW_TYPE} == "xpm")
CONFIGURE_ARGS+=	--with-Xaw3d
.endif

.endif
