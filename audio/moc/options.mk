# $NetBSD: options.mk,v 1.6 2016/02/16 08:46:01 leot Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.moc
PKG_SUPPORTED_OPTIONS=	sndfile flac vorbis speex curl samplerate jack
PKG_SUGGESTED_OPTIONS=	sndfile flac vorbis curl

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		flac sndfile speex vorbis

.if !empty(PKG_OPTIONS:Mjack)
CONFIGURE_ARGS+=	--with-jack
###
### Resampling support is usually required with jack.
###
.  include "../../audio/jack/buildlink3.mk"
.  if empty(PKG_OPTIONS:Msamplerate)
PKG_OPTIONS+=		samplerate
.  endif
.else
CONFIGURE_ARGS+=	--without-jack
.endif

.if !empty(PKG_OPTIONS:Msamplerate)
CONFIGURE_ARGS+=	--with-samplerate
.  if empty(PKG_OPTIONS:Msndfile)
PKG_OPTIONS+=		sndfile
.  endif
.  include "../../audio/libsamplerate/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-samplerate
.endif

.if !empty(PKG_OPTIONS:Msndfile)
PLIST.sndfile=		yes
CONFIGURE_ARGS+=	--with-sndfile
.  include "../../audio/libsndfile/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-sndfile
.endif

.if !empty(PKG_OPTIONS:Mflac)
PLIST.flac=		yes
CONFIGURE_ARGS+=	--with-flac
.  include "../../audio/flac/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-flac
.endif

.if !empty(PKG_OPTIONS:Mvorbis)
PLIST.vorbis=		yes
CONFIGURE_ARGS+=	--with-vorbis
.  include "../../audio/libvorbis/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-vorbis
.endif

.if !empty(PKG_OPTIONS:Mspeex)
PLIST.speex=		yes
CONFIGURE_ARGS+=	--with-speex
.  include "../../audio/speex/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-speex
.endif

.if !empty(PKG_OPTIONS:Mcurl)
CONFIGURE_ARGS+=	--with-curl
.  include "../../www/curl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-curl
.endif
