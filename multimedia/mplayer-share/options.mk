# $NetBSD: options.mk,v 1.73 2024/05/27 19:33:55 rjs Exp $

.if defined(PKGNAME) && empty(PKGNAME:Mmplayer-share*)

# Note: This expression is the same as ${PKGBASE}, but the latter is
# not defined yet, so we cannot use it here.
PKG_OPTIONS_VAR=	PKG_OPTIONS.${PKGNAME:C/-[0-9].*//}

.include "../../multimedia/libvdpau/available.mk"
.include "../../comms/lirc/available.mk"

# -------------------------------------------------------------------------
# Define PKG_SUPPORTED_OPTIONS based on the current package and system.
# -------------------------------------------------------------------------

# Note: It is a good practice that all PKG_SUPPORTED_OPTIONS are
# enabled or disabled with --enable-option or --disable-option.
# It is better to add missing libs via EXTRA_LIBS, when it is possible,
# instead of patching the configure script in order to make the update of
# the packages easier.

# Options supported by both mplayer* or mencoder*.

PKG_SUPPORTED_OPTIONS=	gif gnutls jpeg mad dts dv png theora vorbis x264 debug
PKG_SUPPORTED_OPTIONS+=	dvdread dvdnav libmpg123 opus

PKG_SUPPORTED_OPTIONS+=		faad

# Set options based on the specific package being built.
.  if !empty(PKGNAME:M*mplayer*)
PKG_SUPPORTED_OPTIONS+=	aalib alsa caca ggi ladspa mplayer-menu nas
PKG_SUPPORTED_OPTIONS+=	openal pulseaudio sdl

# Seems broken - fails to build.
#PKG_SUPPORTED_OPTIONS+=	jack

.    if ${VDPAU_AVAILABLE} == "yes"
PKG_SUPPORTED_OPTIONS+=	vdpau
.    endif

.    if ${LIRC_AVAILABLE} == "yes"
PKG_SUPPORTED_OPTIONS+=	lirc
.    endif

.  elif !empty(PKGNAME:M*mencoder*)
PKG_SUPPORTED_OPTIONS+=	faac lame
.  endif

# OS-specific options.
.  if ${OPSYS} == "FreeBSD" || ${OPSYS} == "Linux" || ${OPSYS} == "NetBSD"
PKG_SUPPORTED_OPTIONS+=		cdparanoia
.  endif
PKG_SUPPORTED_OPTIONS.SunOS+=	mlib
PKG_SUPPORTED_OPTIONS.Linux+=	vidix

.  if ${OPSYS} == "NetBSD" || ${OPSYS} == "Linux"
PKG_SUPPORTED_OPTIONS+=	v4l2
PKG_SUGGESTED_OPTIONS+=	v4l2
.  endif

# Platform-specific options.
.  if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64" || \
    ${MACHINE_ARCH} == "powerpc"
PKG_SUPPORTED_OPTIONS+=	mplayer-runtime-cpudetection
.  endif
.  if ${MACHINE_ARCH} == "i386"
PKG_SUPPORTED_OPTIONS+=	mplayer-win32
.  endif
.  if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
PKG_SUPPORTED_OPTIONS+=	mplayer-ssse3
.  endif
.  if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64" || \
    ${MACHINE_ARCH} == "powerpc" || ${MACHINE_ARCH} == "sparc64"
PKG_SUPPORTED_OPTIONS+=	xvid
.  endif

# -------------------------------------------------------------------------
# Define PKG_SUGGESTED_OPTIONS.
# -------------------------------------------------------------------------

.  for o in   dvdread dvdnav gif gnutls jpeg \
	    ladspa mplayer-menu \
	    mplayer-runtime-cpudetection \
	    png sdl vdpau lirc
.    if !empty(PKG_SUPPORTED_OPTIONS:M${o})
PKG_SUGGESTED_OPTIONS+=		${o}
.    endif
.  endfor
.  if !empty(PKGNAME:M*mplayer*)
PKG_SUGGESTED_OPTIONS.Linux+=	alsa
.  endif
PKG_SUGGESTED_OPTIONS.Linux+=	vidix

# -------------------------------------------------------------------------
# Handle extra libraries (part 1)
# -------------------------------------------------------------------------
EXTRA_LIBS=

# -------------------------------------------------------------------------
# Handle chosen options.
# -------------------------------------------------------------------------

.include "../../mk/bsd.options.mk"

.  if !empty(PKG_OPTIONS:Maalib)
CONFIGURE_ARGS+=	--enable-aa
.    include "../../graphics/aalib/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--disable-aa
.  endif

.  if !empty(PKG_OPTIONS:Malsa)
CONFIGURE_ARGS+=	--enable-alsa
.    include "../../audio/alsa-lib/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--disable-alsa
.  endif

.  if !empty(PKG_OPTIONS:Mcaca)
CONFIGURE_ARGS+=	--enable-caca
.    include "../../graphics/libcaca/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--disable-caca
.  endif

.  if !empty(PKG_OPTIONS:Mcdparanoia)
CONFIGURE_ARGS+=	--enable-cdparanoia
.    include "../../audio/cdparanoia/buildlink3.mk"
CFLAGS+=		-I${BUILDLINK_PREFIX.cdparanoia}/include/cdparanoia
.  else
CONFIGURE_ARGS+=	--disable-cdparanoia
.  endif

.  if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug --disable-sighandler
INSTALL_UNSTRIPPED=	yes
.  endif

.  if !empty(PKG_OPTIONS:Mdts)
# The configure handling for --enable-libdca is broken.
# However, it works if you omit the argument and let
# configure autodetect support.
#CONFIGURE_ARGS+=       --enable-libdca
.    include "../../audio/libdca/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--disable-libdca
.  endif

.  if !empty(PKG_OPTIONS:Mdv)
CONFIGURE_ARGS+=	--enable-libdv
.    include "../../multimedia/libdv/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--disable-libdv
.  endif

.  if !empty(PKG_OPTIONS:Mdvdread)
.    include "../../multimedia/libdvdread/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--disable-dvdread
.  endif

.  if !empty(PKG_OPTIONS:Mdvdnav)
CONFIGURE_ARGS+=	--enable-dvdnav
.    include "../../multimedia/libdvdnav/buildlink3.mk"
#CFLAGS+=		-I${BUILDLINK_PREFIX.libdvdnav}/include/dvdnav
.  else
CONFIGURE_ARGS+=	--disable-dvdnav
.  endif

.  if !empty(PKG_OPTIONS:Mfaac)
CONFIGURE_ARGS+=	--enable-faac
EXTRA_LIBS+=		-lfaac
.    include "../../audio/faac/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--disable-faac
.  endif

.  if !empty(PKG_OPTIONS:Mfaad)
CONFIGURE_ARGS+=	--enable-faad
.    include "../../audio/faad2/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--disable-faad
.  endif

.  if !empty(PKG_OPTIONS:Mggi)
CONFIGURE_ARGS+=	--enable-ggi
.    include "../../graphics/libggi/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--disable-ggi
.  endif

.  if !empty(PKG_OPTIONS:Mgif)
CONFIGURE_ARGS+=	--enable-gif
.    include "../../graphics/giflib/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--disable-gif
.  endif

.  if !empty(PKG_OPTIONS:Mjpeg)
CONFIGURE_ARGS+=	--enable-jpeg
.    include "../../mk/jpeg.buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--disable-jpeg
.  endif

.  if !empty(PKG_OPTIONS:Mlibmpg123)
# no --enable-mpg123: configure forgets to add -lmpg123.
.    include "../../audio/mpg123/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--disable-mpg123
.  endif

.  if !empty(PKG_OPTIONS:Mlame)
CONFIGURE_ARGS+=	--enable-mp3lame
.    include "../../audio/lame/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--disable-mp3lame
.  endif

.  if !empty(PKG_OPTIONS:Mopus)
CONFIGURE_ARGS+=	--enable-libopus
.    include "../../audio/libopus/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--disable-libopus
.  endif

.  if !empty(PKG_OPTIONS:Mmad)
CONFIGURE_ARGS+=	--enable-mad
.    include "../../audio/libmad/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--disable-mad
.  endif

.  if !empty(PKG_OPTIONS:Mmlib)
CONFIGURE_ARGS+=	--enable-mlib
.  else
CONFIGURE_ARGS+=	--disable-mlib
.  endif

.  if !empty(PKG_OPTIONS:Mmplayer-menu)
CONFIGURE_ARGS+=	--enable-menu
.  else
CONFIGURE_ARGS+=	--disable-menu
.  endif

.  if !empty(PKG_OPTIONS:Mmplayer-runtime-cpudetection)
CONFIGURE_ARGS+=	--enable-runtime-cpudetection
.  else
CONFIGURE_ARGS+=	--disable-runtime-cpudetection
.  endif

.  if !empty(PKG_OPTIONS:Mmplayer-win32)
CONFIGURE_ARGS+=	--enable-win32dll
DEPENDS+=		win32-codecs>=011227:../../multimedia/win32-codecs
.  else
CONFIGURE_ARGS+=	--disable-win32dll
.  endif

.  if !empty(PKG_OPTIONS:Mnas)
CONFIGURE_ARGS+=	--enable-nas
.    include "../../audio/nas/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--disable-nas
.  endif

.  if !empty(PKG_OPTIONS:Mpng)
CONFIGURE_ARGS+=	--enable-png
.    include "../../graphics/png/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--disable-png
.  endif

.  if !empty(PKG_OPTIONS:Mpulseaudio)
CONFIGURE_ARGS+=	--enable-pulse
.    include "../../devel/glib2/buildlink3.mk"
.    include "../../audio/pulseaudio/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--disable-pulse
.  endif

.  if !empty(PKG_OPTIONS:Msdl)
CONFIGURE_ARGS+=	--enable-sdl
.    include "../../devel/SDL/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--disable-sdl
.  endif

.  if !empty(PKG_OPTIONS:Mtheora)
CONFIGURE_ARGS+=	--enable-theora
.    include "../../multimedia/libtheora/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--disable-theora
.  endif

.if !empty(PKG_OPTIONS:Mv4l2)
CONFIGURE_ARGS+=	--enable-tv-v4l2
.  include "../../graphics/libv4l/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-tv-v4l2
.  endif

# disable vidix if not in options
.  if empty(PKG_OPTIONS:Mvidix)
CONFIGURE_ARGS+=	--disable-vidix
.  endif

.  if !empty(PKG_OPTIONS:Mvorbis)
.    include "../../audio/libvorbis/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--disable-libvorbis
.  endif

.  if !empty(PKG_OPTIONS:Mx264)
CONFIGURE_ARGS+=	--enable-x264
EXTRA_LIBS+=		-lx264
.    include "../../multimedia/x264/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--disable-x264
.  endif

.  if !empty(PKG_OPTIONS:Mxvid)
CONFIGURE_ARGS+=	--enable-xvid
EXTRA_LIBS+=		-lxvidcore
.    include "../../multimedia/xvidcore/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--disable-xvid
.  endif

.  if empty(PKG_OPTIONS:Mmplayer-ssse3)
CONFIGURE_ARGS+=	--disable-ssse3
.  endif

.  if !empty(PKG_OPTIONS:Mvdpau)
CONFIGURE_ARGS+=	--enable-vdpau
.    include "../../multimedia/libvdpau/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--disable-vdpau
.  endif

.  if !empty(PKG_OPTIONS:Mlirc)
CONFIGURE_ARGS+=	--enable-lirc
.    include "../../comms/lirc/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--disable-lirc
.  endif

.  if !empty(PKG_OPTIONS:Mgnutls)
CONFIGURE_ARGS+=	--enable-gnutls
.    include "../../security/gnutls/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--disable-gnutls
.  endif

.  if !empty(PKG_OPTIONS:Mjack)
CONFIGURE_ARGS+=	--enable-jack
.    include "../../audio/jack/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--disable-jack
.  endif

.  if !empty(PKG_OPTIONS:Mopenal)
CONFIGURE_ARGS+=	--enable-openal
.    include "../../audio/openal-soft/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--disable-openal
.  endif

.  if !empty(PKG_OPTIONS:Mladspa)
CONFIGURE_ARGS+=	--enable-ladspa
.    include "../../audio/ladspa/buildlink3.mk"
.  else
CONFIGURE_ARGS+=	--disable-ladspa
.  endif

# -------------------------------------------------------------------------
# Handle extra libraries (part 1)
# -------------------------------------------------------------------------
.  if ${EXTRA_LIBS} != ""
CONFIGURE_ARGS+=	--extra-libs=${EXTRA_LIBS:C/^ //:Q}
.  endif

.endif # defined(PKGNAME) && empty(PKGNAME:Mmplayer-share*)
