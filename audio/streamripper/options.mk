# $NetBSD: options.mk,v 1.2 2015/02/19 00:20:47 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.streamripper
PKG_SUPPORTED_OPTIONS=	ogg
PKG_SUGGESTED_OPTIONS=	ogg

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mogg)
.  include "../../audio/libvorbis/buildlink3.mk"
CONFIGURE_ARGS+=	--with-ogg=${BUILDLINK_PREFIX.libvorbis}
.else
CONFIGURE_ARGS+=	--disable-ogg
.endif
