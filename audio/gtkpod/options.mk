# $NetBSD: options.mk,v 1.3 2007/02/09 20:32:38 drochner Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.gtkpod
PKG_SUPPORTED_OPTIONS=		mpeg4ip
PKG_SUGGESTED_OPTIONS=
PKG_OPTIONS_LEGACY_OPTS+=	faad:mpeg4ip

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmpeg4ip)
.  include "../../multimedia/libmp4v2/buildlink3.mk"
.endif
