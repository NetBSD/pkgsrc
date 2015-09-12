# $NetBSD: options.mk,v 1.2 2015/09/12 12:54:10 gdt Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.geeqie
PKG_SUPPORTED_OPTIONS=	libchamplain
# The libchamplain option doesn't actually work, so leave it off
# to avoid the pain of dependencies with no benefit, until debugged.
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibchamplain)
CONFIGURE_ARGS+=	--enable-gps
CONFIGURE_ARGS+=	--enable-clutter
.include "../../geography/libchamplain04/buildlink3.mk"
.include "../../graphics/clutter/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gps
.endif
