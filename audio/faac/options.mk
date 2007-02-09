# $NetBSD: options.mk,v 1.4 2007/02/09 20:27:16 drochner Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.faac
PKG_SUPPORTED_OPTIONS=		mpeg4ip
PKG_SUGGESTED_OPTIONS=
PKG_OPTIONS_LEGACY_OPTS+=	faad:mpeg4ip

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmpeg4ip)
.  include "../../multimedia/libmp4v2/buildlink3.mk"
.else
# ignore bundled mp4v2 lib
CONFIGURE_ARGS+= --without-mp4v2
.endif
