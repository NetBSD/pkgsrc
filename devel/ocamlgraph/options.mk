# $NetBSD: options.mk,v 1.1 2014/10/26 13:43:48 jaapb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.ocamlgraph
PKG_SUPPORTED_OPTIONS=	lablgtk

.include "../../mk/bsd.prefs.mk"

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	lablgtk
###
### Lablgtk support
###
.if !empty(PKG_OPTIONS:Mlablgtk)
PLIST.lablgtk=	yes
USE_LABLGTK=	yes
INSTALLATION_DIRS+=	bin
.include "../../x11/ocaml-lablgtk/buildlink3.mk"
.else
USE_LABLGTK=	no
.endif
