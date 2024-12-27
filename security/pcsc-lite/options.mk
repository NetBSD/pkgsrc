# $NetBSD: options.mk,v 1.5 2024/12/27 12:37:29 gdt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pcsc-lite

PKG_SUPPORTED_OPTIONS=		polkit
# Do not suggest polkit, because pcsc-lite fails to build on NetBSD if it
# is present.  Reported upstream by email 20241227. -gdt
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	polkit

.if !empty(PKG_OPTIONS:Mpolkit)
.include "../../security/polkit/buildlink3.mk"
MESON_ARGS+=		-Dpolkit=true
PLIST.polkit=		yes
.else
MESON_ARGS+=		-Dpolkit=false
.endif
