# $NetBSD: options.mk,v 1.3 2024/08/25 06:18:41 wiz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mgba-qt

PKG_SUPPORTED_OPTIONS+=	ffmpeg
PKG_SUGGESTED_OPTIONS+=	ffmpeg

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mffmpeg)
CMAKE_CONFIGURE_ARGS+=	-DUSE_FFMPEG=ON
.include "../../multimedia/ffmpeg6/buildlink3.mk"
.else
CMAKE_CONFIGURE_ARGS+=	-DUSE_FFMPEG=OFF
.endif
