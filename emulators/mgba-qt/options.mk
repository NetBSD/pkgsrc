# $NetBSD: options.mk,v 1.2 2023/11/19 22:56:13 nia Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.mgba-qt

PKG_SUPPORTED_OPTIONS+=	ffmpeg
PKG_SUGGESTED_OPTIONS+=	ffmpeg

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mffmpeg)
CMAKE_ARGS+=	-DUSE_FFMPEG=ON
.include "../../multimedia/ffmpeg6/buildlink3.mk"
.else
CMAKE_ARGS+=	-DUSE_FFMPEG=OFF
.endif
