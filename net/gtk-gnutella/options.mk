# $NetBSD: options.mk,v 1.5 2022/12/25 17:55:14 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.gtk-gnutella
PKG_SUPPORTED_OPTIONS=		# empty
PKG_OPTIONS_OPTIONAL_GROUPS=	gui
PKG_OPTIONS_GROUP.gui=		gtk2 headless
PKG_SUGGESTED_OPTIONS=		gtk2

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk2)
CONFIGURE_ARGS+=	--gtk2
.  include "../../x11/gtk2/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mheadless)
CONFIGURE_ARGS+=	--topless
.  include "../../devel/glib2/buildlink3.mk"
.endif
