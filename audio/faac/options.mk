# $NetBSD: options.mk,v 1.2 2006/06/07 21:33:21 hira Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.faac
PKG_SUPPORTED_OPTIONS=	mpeg4ip
PKG_SUGGESTED_OPTIONS=
PKG_OPTIONS_LEGACY_OPTS+=faad:mpeg4ip

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmpeg4ip)
.  include "../../multimedia/mpeg4ip/buildlink3.mk"
.endif
