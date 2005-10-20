# $NetBSD: options.mk,v 1.1.1.1 2005/10/20 19:55:49 xtraeme Exp $

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
