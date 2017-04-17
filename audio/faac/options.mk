# $NetBSD: options.mk,v 1.5 2017/04/17 08:45:17 wiz Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.faac
PKG_SUPPORTED_OPTIONS=		libmp4v2
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mlibmp4v2)
.  include "../../multimedia/libmp4v2/buildlink3.mk"
.else
# ignore bundled mp4v2 lib
CONFIGURE_ARGS+= --without-mp4v2
.endif
