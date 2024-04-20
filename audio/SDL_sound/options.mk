# $NetBSD: options.mk,v 1.1 2024/04/20 07:35:24 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.SDL_sound
PKG_SUPPORTED_OPTIONS=	physfs
PKG_SUGGESTED_OPTIONS=	physfs

.include "../../mk/bsd.options.mk"

# physfs is only used in the command-line utility.
.if !empty(PKG_OPTIONS:Mphysfs)
CONFIGURE_ARGS+=	--enable-physfs
.  include "../../devel/physfs/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-physfs
.endif
