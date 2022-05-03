# $NetBSD: options.mk,v 1.11 2022/05/03 09:40:28 jaapb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ocamlnet
PKG_SUPPORTED_OPTIONS=	gtk2 gnutls
PKG_SUGGESTED_OPTIONS=	gnutls

PLIST_VARS+=		gnutls

.include "../../mk/bsd.prefs.mk"

.include "../../mk/bsd.options.mk"

###
### GTK2 support
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
OCAML_FINDLIB_DIRS+=	nettls-gnutls
CONFIGURE_ARGS+=	-enable-gnutls
.else
CONFIGURE_ARGS+=	-disable-gnutls
.endif
