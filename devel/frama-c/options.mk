# $NetBSD: options.mk,v 1.4 2017/09/05 07:30:00 dholland Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.frama-c
PKG_SUPPORTED_OPTIONS=	gui coq
PKG_SUGGESTED_OPTIONS=	gui coq

PLIST_VARS=	gui coq

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgui)
PLIST.gui=	yes

.include "../../x11/ocaml-lablgtk/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--enable-gui=no
.endif

.if !empty(PKG_OPTIONS:Mcoq)
PLIST.coq=	yes

DEPENDS+=		coq>=8.6:../../lang/coq
.else
CONFIGURE_ARGS+=	--enable-wp-coq=no
.endif
