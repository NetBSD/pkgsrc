# $NetBSD: options.mk,v 1.8 2024/02/19 19:39:00 gdt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.unison
PKG_SUPPORTED_OPTIONS=	lablgtk
# ocaml-cairo is broken
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	gtk3

.if !empty(PKG_OPTIONS:Mlablgtk)
PLIST.gtk3=	yes
DEPENDS+=	font-schumacher-misc>=1.0:../../fonts/font-schumacher-misc

.include "../../x11/ocaml-lablgtk3/buildlink3.mk"
.endif
