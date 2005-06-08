# $NetBSD: options.mk,v 1.4 2005/06/08 16:18:44 dillo Exp $

.if defined(PKGNAME) && empty(PKGNAME:Mmplayer-share*)

PKG_OPTIONS_VAR=	PKG_OPTIONS.${PKGNAME:C/-[0-9].*//}

.include "../../mk/bsd.prefs.mk"

# -------------------------------------------------------------------------
# Define PKG_SUPPORTED_OPTIONS based on the current package and system.
# -------------------------------------------------------------------------

# Options supported by both mplayer* or mencoder*.
PKG_SUPPORTED_OPTIONS=	gif jpeg mad dv dvdread oss png theora vorbis

# Set options based on the specific package being built.
.if !empty(PKGNAME:M*mplayer*)
PKG_SUPPORTED_OPTIONS+=	esound mplayer-menu nas sdl

.  if ${OPSYS} != "SunOS"
PKG_SUPPORTED_OPTIONS+=	arts
.  endif
.elif !empty(PKGNAME:M*mencoder*)
PKG_SUPPORTED_OPTIONS+=	lame
.endif

# OS-specific options.
.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "Linux" || ${OPSYS} == "NetBSD"
PKG_SUPPORTED_OPTIONS+=	cdparanoia
.elif ${OPSYS} == "SunOS"
PKG_SUPPORTED_OPTIONS+=	mlib
.endif

# Platform-specific options.
.if ${MACHINE_ARCH} == "i386"
PKG_SUPPORTED_OPTIONS+= mplayer-runtime-cpudetection mplayer-win32 \
			xvid
.endif
.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "powerpc" || \
    ${MACHINE_ARCH} == "alpha"
PKG_SUPPORTED_OPTIONS+=	mplayer-real
.endif

# -------------------------------------------------------------------------
# Define PKG_SUGGESTED_OPTIONS.
# -------------------------------------------------------------------------

.for _o_ in arts cdparanoia dv dvdread esound gif jpeg \
	    lame mad mplayer-menu mplayer-real \
	    mplayer-runtime-cpudetection mplayer-win32 \
	    nas oss png sdl theora vorbis xvid 
.  if !empty(PKG_SUPPORTED_OPTIONS:M${_o_})
PKG_SUGGESTED_OPTIONS+=	${_o_}
.  endif
.endfor

# -------------------------------------------------------------------------
# Define PKG_SUGGESTED_OPTIONS based on deprecated variables.
# -------------------------------------------------------------------------

.for d in ${MPLAYER_DISABLE_DRIVERS}
PKG_LEGACY_OPTIONS+=-${d:S/esd/esound/}
PKG_OPTIONS_DEPRECATED_WARNINGS+="Deprecated variable MPLAYER_DISABLE_DRIVERS="${d:Q}" used; use "${PKG_OPTIONS_VAR:Q}"+=-"${d:S/esd/esound/:Q}" instead."
.endfor

.if ${MACHINE_ARCH} == "i386"
PKG_OPTIONS_LEGACY_VARS+=	\
	MPLAYER_ENABLE_RUNTIME_CPU_DETECTION:mplayer-runtime-cpudetection
.endif

.if ${OPSYS} == "SunOS"
PKG_OPTIONS_LEGACY_VARS+=	MPLAYER_USE_MEDIALIB:mlib
.endif

# -------------------------------------------------------------------------
# Handle chosen options.
# -------------------------------------------------------------------------

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Marts)
CONFIGURE_ARGS+=	--enable-arts
.  include "../../audio/arts/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-arts
.endif

.if !empty(PKG_OPTIONS:Mcdparanoia)
CONFIGURE_ARGS+=	--enable-cdparanoia
CONFIGURE_ARGS+=	--with-cdparanoiaincdir="${BUILDLINK_PREFIX.cdparanoia}/include/cdparanoia"
.  include "../../audio/cdparanoia/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-cdparanoia
.endif

.if !empty(PKG_OPTIONS:Mdv)
CONFIGURE_ARGS+=	--enable-libdv
.  include "../../multimedia/libdv/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-libdv
.endif

.if !empty(PKG_OPTIONS:Mdvdread)
CONFIGURE_ARGS+=	--enable-dvdread
.  include "../../multimedia/libdvdread/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-dvdread
.endif

.if !empty(PKG_OPTIONS:Mesound)
CONFIGURE_ARGS+=	--enable-esd
.  include "../../audio/esound/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-esd
.endif

.if !empty(PKG_OPTIONS:Mgif)
CONFIGURE_ARGS+=	--enable-gif
.  include "../../graphics/libungif/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gif
.endif

.if !empty(PKG_OPTIONS:Mjpeg)
CONFIGURE_ARGS+=	--enable-jpeg
.  include "../../graphics/jpeg/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-jpeg
.endif

.if !empty(PKG_OPTIONS:Mlame)
#CONFIGURE_ARGS+=	--enable-toolame
.  include "../../audio/lame/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-toolame
.endif

.if !empty(PKG_OPTIONS:Mmad)
CONFIGURE_ARGS+=	--enable-mad
.  include "../../audio/libmad/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-mad
.endif

.if !empty(PKG_OPTIONS:Mmlib)
CONFIGURE_ARGS+=	--enable-mlib
.else
CONFIGURE_ARGS+=	--disable-mlib
.endif

.if !empty(PKG_OPTIONS:Mmplayer-menu)
CONFIGURE_ARGS+=	--enable-menu
.else
CONFIGURE_ARGS+=	--disable-menu
.endif

.if !empty(PKG_OPTIONS:Mmplayer-real)
EVAL_PREFIX+=		PREFIX.realplayer-codecs=realplayer-codecs
PREFIX.realplayer-codecs_DEFAULT=	${LOCALBASE}
CONFIGURE_ARGS+=	--enable-real
CONFIGURE_ARGS+=	--with-reallibdir="${PREFIX.realplayer-codecs}/lib/RealPlayer8-Codecs"
DEPENDS+=		realplayer-codecs>=8nb2:../../multimedia/realplayer-codecs
.else
CONFIGURE_ARGS+=	--disable-real
.endif

.if !empty(PKG_OPTIONS:Mmplayer-runtime-cpudetection)
CONFIGURE_ARGS+=	--enable-runtime-cpudetection
.else
CONFIGURE_ARGS+=	--disable-runtime-cpudetection
.endif

.if !empty(PKG_OPTIONS:Mmplayer-win32)
EVAL_PREFIX+=		PREFIX.win32-codecs=win32-codecs
PREFIX.win32-codecs_DEFAULT=	${LOCALBASE}
CONFIGURE_ARGS+=	--enable-win32
CONFIGURE_ARGS+=	--with-win32libdir="${PREFIX.win32-codecs}/lib/win32"
DEPENDS+=		win32-codecs>=011227:../../multimedia/win32-codecs
.else
CONFIGURE_ARGS+=	--disable-win32
.endif

.if !empty(PKG_OPTIONS:Mnas)
CONFIGURE_ARGS+=	--enable-nas
.  include "../../audio/nas/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-nas
.endif

.if !empty(PKG_OPTIONS:Moss)
CONFIGURE_ARGS+=	--enable-ossaudio
.  include "../../mk/ossaudio.buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-ossaudio
.endif

.if !empty(PKG_OPTIONS:Mpng)
CONFIGURE_ARGS+=	--enable-png
.  include "../../graphics/png/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-png
.endif

.if !empty(PKG_OPTIONS:Msdl)
CONFIGURE_ARGS+=	--enable-sdl
.  include "../../devel/SDL/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-sdl
.endif

.if !empty(PKG_OPTIONS:Mtheora)
CONFIGURE_ARGS+=	--enable-theora
.  include "../../multimedia/libtheora/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-theora
.endif

.if !empty(PKG_OPTIONS:Mvorbis)
CONFIGURE_ARGS+=	--enable-vorbis
.  include "../../audio/libvorbis/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-vorbis
.endif

.if !empty(PKG_OPTIONS:Mxvid)
CONFIGURE_ARGS+=	--enable-xvid
.  include "../../multimedia/xvidcore/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-xvid
.endif

.endif # defined(PKGNAME) && empty(PKGNAME:Mmplayer-share*)
