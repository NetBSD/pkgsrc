# $NetBSD: options.mk,v 1.6 2007/06/15 21:40:54 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mldonkey-gui
PKG_OPTIONS_REQUIRED_GROUPS+=	toolkit
PKG_OPTIONS_GROUP.toolkit=	lablgtk lablgtk2
PKG_SUGGESTED_OPTIONS=	lablgtk2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlablgtk)
CONFIGURE_ARGS+=	--enable-gui=newgui1
.include "../../x11/lablgtk/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlablgtk2)
CONFIGURE_ARGS+=	--enable-gui=newgui2
.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
# 2.6.0 is the first ~stable version (for mldonkey)
BUILDLINK_API_DEPENDS.lablgtk2+=	lablgtk2>=2.6.0
.include "../../x11/lablgtk2/buildlink3.mk"
.endif
