# $NetBSD: options.mk,v 1.2 2015/02/05 16:57:36 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libretro-pcsx-rearmed

.include "../../mk/bsd.fast.prefs.mk"

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
