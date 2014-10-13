# $NetBSD: options.mk,v 1.2 2014/10/13 12:37:50 jaapb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ocamlnet
PKG_SUPPORTED_OPTIONS=	ssl gtk gtk2
PKG_SUGGESTED_OPTIONS=	ssl

.include "../../mk/bsd.prefs.mk"

.include "../../mk/bsd.options.mk"

###
### SSL support
###
.if !empty(PKG_OPTIONS:Mssl)
.  include "../../security/ocaml-ssl/buildlink3.mk"
CONFIGURE_ARGS+=	-enable-ssl
PLIST.ssl=		yes
.else
CONFIGURE_ARGS+=	-disable-ssl
.endif

###
### GTK(1) support
###
.if !empty(PKG_OPTIONS:Mgtk)
.  include  "../../x11/lablgtk1/buildlink3.mk"
CONFIGURE_ARGS+=	-enable-gtk
.else
CONFIGURE_ARGS+=	-disable-gtk
.endif

###
### GTK(2) support
###
.if !empty(PKG_OPTIONS:Mgtk2)
.  include  "../../x11/ocaml-lablgtk/buildlink3.mk"
CONFIGURE_ARGS+=	-enable-gtk2
.else
CONFIGURE_ARGS+=	-disable-gtk2
.endif
