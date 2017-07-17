# $NetBSD: options.mk,v 1.7 2017/07/17 12:30:55 jaapb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ocamlnet
PKG_SUPPORTED_OPTIONS=	gtk gtk2 gnutls cmxs
PKG_SUGGESTED_OPTIONS=	gnutls

PLIST_VARS+=		gnutls cmxs

.include "../../mk/bsd.prefs.mk"

.include "../../mk/bsd.options.mk"

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

###
### GNU TLS support
###
.if !empty(PKG_OPTIONS:Mgnutls)
.  include "../../security/gnutls/buildlink3.mk"
PLIST.gnutls=		yes
CONFIGURE_ARGS+=	-enable-gnutls
.else
CONFIGURE_ARGS+=	-disable-gnutls
.endif

###
### cmxs support
###
.if !empty(PKG_OPTIONS:Mcmxs)
PLIST.cmxs=	yes
MAKE_ENV+=	HAVE_SHARED=1
.else
MAKE_ENV+=	HAVE_SHARED=0
.endif
