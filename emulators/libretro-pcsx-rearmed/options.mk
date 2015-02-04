# $NetBSD: options.mk,v 1.1 2015/02/04 23:04:17 jmcneill Exp $

.include "../../mk/bsd.prefs.mk"

PKG_OPTIONS_VAR=	PKG_OPTIONS.libretro-pcsx-rearmed

.if !empty(MACHINE_ARCH:M*arm*)
PKG_SUPPORTED_OPTIONS+=	dynarec
PKG_SUGGESTED_OPTIONS+=	dynarec
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdynarec)
# enabled by default
.else
CONFIGURE_ARGS+=	--disable-dynarec
.endif
