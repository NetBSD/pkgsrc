# $NetBSD: options.mk,v 1.1 2005/10/06 11:51:13 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mldonkey-gui
PKG_OPTIONS_REQUIRED_GROUPS+=	toolkit
PKG_OPTIONS_GROUP.toolkit=	lablgtk lablgtk2
# lablgtk2 GUI segfaults easily
PKG_SUGGESTED_OPTIONS=	lablgtk

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlablgtk)
CONFIGURE_ARGS+=	--enable-gui=newgui1
.include "../../x11/lablgtk/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mlablgtk2)
CONFIGURE_ARGS+=	--enable-gui=newgui2
.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
# 2.4.0nb3 was first version with included optimized files on which
# mldonkey configure script insists
BUILDLINK_DEPENDS.lablgtk2+=	lablgtk2>=2.4.0nb3
.include "../../x11/lablgtk2/buildlink3.mk"
.endif
