# $NetBSD: options.mk,v 1.8 2007/09/21 13:04:13 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mldonkey-gui
PKG_OPTIONS_REQUIRED_GROUPS+=	toolkit
PKG_OPTIONS_GROUP.toolkit=	lablgtk1 lablgtk
PKG_SUGGESTED_OPTIONS=	lablgtk

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlablgtk1)
CONFIGURE_ARGS+=	--enable-gui=newgui1
.include "../../x11/lablgtk1/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlablgtk)
CONFIGURE_ARGS+=	--enable-gui=newgui2
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
# 2.6.0 is the first ~stable version (for mldonkey)
BUILDLINK_API_DEPENDS.lablgtk+=	lablgtk>=2.6.0
.include "../../x11/lablgtk/buildlink3.mk"
.endif
