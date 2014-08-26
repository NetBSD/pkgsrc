# $NetBSD: options.mk,v 1.1 2014/08/26 10:44:15 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.libopenmpt
PKG_SUPPORTED_OPTIONS=	flac sndfile wavpack
PKG_SUGGESTED_OPTIONS=	sndfile

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mflac)
.include "../../audio/flac/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Msndfile)
.include "../../audio/libsndfile/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mwavpack)
.include "../../audio/wavpack/buildlink3.mk"
.endif
