# $NetBSD: options.mk,v 1.3 2016/02/03 13:19:26 jaapb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ocamlnet
PKG_SUPPORTED_OPTIONS=	gtk gtk2
PKG_SUGGESTED_OPTIONS=	

.include "../../mk/bsd.prefs.mk"

.include "../../mk/bsd.options.mk"

###
### SSL support
###
#.if !empty(PKG_OPTIONS:Mssl)
#.  include "../../security/ocaml-ssl/buildlink3.mk"
#CONFIGURE_ARGS+=	-enable-ssl
#PLIST.ssl=		yes
#.else
#CONFIGURE_ARGS+=	-disable-ssl
#.endif

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
