# $NetBSD: options.mk,v 1.1 2025/01/26 15:12:27 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.mtpaint
PKG_OPTIONS_OPTIONAL_GROUPS=	toolkit
PKG_OPTIONS_GROUP.toolkit=	gtk2 gtk3
PKG_SUGGESTED_OPTIONS=		gtk3

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk2)
.  include "../../x11/gtk2/buildlink3.mk"
CONFIGURE_ARGS+=	gtk2
.endif

.if !empty(PKG_OPTIONS:Mgtk3)
.  include "../../x11/gtk3/buildlink3.mk"
CONFIGURE_ARGS+=	gtk3
.endif
