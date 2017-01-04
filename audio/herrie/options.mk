# $NetBSD: options.mk,v 1.9 2017/01/04 16:47:59 roy Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.herrie
PKG_SUPPORTED_OPTIONS=		curl libao modplug libspiff sndfile	\
				vorbis wide-curses
PKG_SUGGESTED_OPTIONS=		curl
PKG_OPTIONS_LEGACY_OPTS+=	ncursesw:wide-curses

.include "../../mk/curses.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"

.if ${OSS_TYPE} == "native"
PKG_SUPPORTED_OPTIONS+=		oss
PKG_SUGGESTED_OPTIONS+=		oss
.elif ${OSS_TYPE} == "none"
PKG_SUGGESTED_OPTIONS+=		libao
.endif

.include "../../mk/bsd.fast.prefs.mk"
.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mcurl)
.  include "../../www/curl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	no_http
CONFIGURE_ARGS+=	no_scrobbler
.endif

.if !empty(PKG_OPTIONS:Mlibao)
CONFIGURE_ARGS+=	ao
.  include "../../audio/libao/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mmodplug)
.  include "../../audio/libmodplug/buildlink3.mk"
.else
CONFIGURE_ARGS+=	no_modplug
.endif

.if !empty(PKG_OPTIONS:Mlibspiff)
.  include "../../audio/libspiff/buildlink3.mk"
.else
CONFIGURE_ARGS+=	no_xspf
.endif

.if !empty(PKG_OPTIONS:Moss)
CONFIGURE_ARGS+=	oss
LDFLAGS+=		${BUILDLINK_LDADD.oss}
HERRIE_USE_OSS=		# empty
.else
HERRIE_USE_OSS=		\#
.endif

.if !empty(PKG_OPTIONS:Msndfile)
.  include "../../audio/libsndfile/buildlink3.mk"
.else
CONFIGURE_ARGS+=	no_sndfile
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	no_strip strict
.endif

.if !empty(PKG_OPTIONS:Mvorbis)
.  include "../../audio/libvorbis/buildlink3.mk"
.else
CONFIGURE_ARGS+=	no_vorbis
.endif
