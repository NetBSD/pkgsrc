# $NetBSD: options.mk,v 1.1 2021/12/01 14:35:15 pho Exp $
PKG_OPTIONS_VAR=		PKG_OPTIONS.mp3fs
PKG_OPTIONS_NONEMPTY_SETS=	decoders
PKG_OPTIONS_SET.decoders=	flac vorbis
PKG_SUGGESTED_OPTIONS=		flac vorbis

.include "../../mk/bsd.options.mk"

###
### FLAC support
###
.if !empty(PKG_OPTIONS:Mflac)
.include "../../audio/flac/buildlink3.mk"
.endif

###
### Ogg Vorbis support
###
.if !empty(PKG_OPTIONS:Mvorbis)
.include "../../audio/libvorbis/buildlink3.mk"
.endif
