# $NetBSD: options.mk,v 1.6 2024/12/27 14:39:53 gdt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pcsc-lite

PKG_SUPPORTED_OPTIONS=		polkit
# polkit is only used on systems that support LOCALCRED (but not
# LOCAL_CREDS).  \todo Don't suggest on systems where it doesn't help,
# to reduce bloat.
PKG_SUGGESTED_OPTIONS=		polkit

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	polkit

.if !empty(PKG_OPTIONS:Mpolkit)
.include "../../security/polkit/buildlink3.mk"
MESON_ARGS+=		-Dpolkit=true
PLIST.polkit=		yes
.else
MESON_ARGS+=		-Dpolkit=false
.endif
