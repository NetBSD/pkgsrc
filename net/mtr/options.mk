# $NetBSD: options.mk,v 1.5 2014/11/19 09:01:51 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mtr
PKG_SUPPORTED_OPTIONS=	gtk glib inet6
PKG_SUGGESTED_OPTIONS=	glib inet6

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgtk)
.include "../../x11/gtk2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-gtk
.endif

.if !empty(PKG_OPTIONS:Mglib) || !empty(PKG_OPTIONS:Mgtk)
.include "../../devel/glib2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-glib
.endif

.if !empty(PKG_OPTIONS:Minet6)
CONFIGURE_ARGS+=        --enable-ipv6
.else
CONFIGURE_ARGS+=        --disable-ipv6
.endif
