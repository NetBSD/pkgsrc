# $NetBSD: options.mk,v 1.1 2014/11/06 11:59:17 jaapb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.dose3

PKG_SUPPORTED_OPTIONS=		ocamlgraph
PKG_SUGGESTED_OPTIONS=		ocamlgraph

.include "../../mk/bsd.options.mk"

###
### Use Ocamlgraph
###
PLIST_VARS+=	ocamlgraph
.if !empty(PKG_OPTIONS:Mocamlgraph)
.include "../../devel/ocamlgraph/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ocamlgraph
PLIST.ocamlgraph=	yes
.else
CONFIGURE_ARGS+=	--without-ocamlgraph
.endif
