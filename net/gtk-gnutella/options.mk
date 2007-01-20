# $NetBSD: options.mk,v 1.2 2007/01/20 14:50:03 cbiere Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gtk-gnutella
PKG_SUPPORTED_OPTIONS=		# empty
PKG_OPTIONS_OPTIONAL_GROUPS=	gui
PKG_OPTIONS_GROUP.gui=		gtk1 gtk2 headless
PKG_SUGGESTED_OPTIONS=		gtk2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk1)
CONFIGURE_ARGS+=	-D gtkversion=1
.  include "../../x11/gtk/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mgtk2)
CONFIGURE_ARGS+=	-D gtkversion=2
.  include "../../x11/gtk2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mheadless)
CONFIGURE_ARGS+=	-D d_headless
.  include "../../devel/glib2/buildlink3.mk"
.endif
