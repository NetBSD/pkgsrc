# $NetBSD: options.mk,v 1.21 2019/06/03 09:53:50 prlw1 Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.glib2
PKG_SUPPORTED_OPTIONS=	fam
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	fam
.if !empty(PKG_OPTIONS:Mfam)
MESON_ARGS+=	-Dfam=true
PLIST.fam=	yes
.include "../../mk/fam.buildlink3.mk"
.endif
