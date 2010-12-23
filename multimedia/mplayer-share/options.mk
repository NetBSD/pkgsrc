# $NetBSD: options.mk,v 1.43 2010/12/23 11:44:51 dsainty Exp $

.if defined(PKGNAME) && empty(PKGNAME:Mmplayer-share*)

# Note: This expression is the same as ${PKGBASE}, but the latter is
# not defined yet, so we cannot use it here.
PKG_OPTIONS_VAR=	PKG_OPTIONS.${PKGNAME:C/-[0-9].*//}

.include "../../mk/oss.buildlink3.mk"
.include "../../multimedia/libvdpau/available.mk"

# -------------------------------------------------------------------------
# Define PKG_SUPPORTED_OPTIONS based on the current package and system.
# -------------------------------------------------------------------------

# Options supported by both mplayer* or mencoder*.

PKG_SUPPORTED_OPTIONS=	gif jpeg mad dts dv png theora vorbis x264 debug
PKG_SUPPORTED_OPTIONS+= dvdread dvdnav
.if ${OSS_TYPE} != "none"
PKG_SUPPORTED_OPTIONS+=	oss
.endif

PKG_OPTIONS_OPTIONAL_GROUPS=	faadgroup
PKG_OPTIONS_GROUP.faadgroup=	faad mplayer-internal-faad
PKG_SUGGESTED_OPTIONS+=		mplayer-internal-faad

# Set options based on the specific package being built.
.if !empty(PKGNAME:M*mplayer*)
PKG_SUPPORTED_OPTIONS+=	aalib caca esound ggi mplayer-menu nas pulseaudio sdl

.if ${VDPAU_AVAILABLE} == "yes"
PKG_SUPPORTED_OPTIONS+=	vdpau
.endif

.  if ${OPSYS} != "SunOS"
PKG_SUPPORTED_OPTIONS+=	arts
.  endif
.elif !empty(PKGNAME:M*mencoder*)
PKG_SUPPORTED_OPTIONS+=	faac lame
.endif

# OS-specific options.
.if ${OPSYS} == "FreeBSD" || ${OPSYS} == "Linux" || ${OPSYS} == "NetBSD"
PKG_SUPPORTED_OPTIONS+=	cdparanoia
.elif ${OPSYS} == "SunOS"
PKG_SUPPORTED_OPTIONS+=	mlib
.endif
.if ${OPSYS} == "Linux"
PKG_SUPPORTED_OPTIONS+=	vidix
.endif

.if ${OPSYS} == "NetBSD" && exists(/usr/include/sys/videoio.h)
PKG_SUPPORTED_OPTIONS+=	v4l2
PKG_SUGGESTED_OPTIONS+=	v4l2
.endif

# Platform-specific options.
.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64" || \
    ${MACHINE_ARCH} == "powerpc"
PKG_SUPPORTED_OPTIONS+= mplayer-runtime-cpudetection
.endif
.if ${MACHINE_ARCH} == "i386"
PKG_SUPPORTED_OPTIONS+= mplayer-default-cflags mplayer-win32
.endif
.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "powerpc" || \
    ${MACHINE_ARCH} == "alpha"
PKG_SUPPORTED_OPTIONS+=	mplayer-real
.endif
.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64"
PKG_SUPPORTED_OPTIONS+=	mplayer-ssse3
.endif
.if ${MACHINE_ARCH} == "i386" || ${MACHINE_ARCH} == "x86_64" || \
    ${MACHINE_ARCH} == "powerpc" || ${MACHINE_ARCH} == "sparc64"
PKG_SUPPORTED_OPTIONS+= xvid
.endif

# -------------------------------------------------------------------------
# Define PKG_SUGGESTED_OPTIONS.
# -------------------------------------------------------------------------

.for _o_ in aalib arts cdparanoia dv esound gif jpeg \
	    dvdread dvdnav \
	    lame mad mplayer-menu mplayer-real \
	    mplayer-default-cflags mplayer-runtime-cpudetection mplayer-win32 \
	    nas oss pulseaudio png sdl theora vorbis x264 xvid vdpau
.  if !empty(PKG_SUPPORTED_OPTIONS:M${_o_})
PKG_SUGGESTED_OPTIONS+=	${_o_}
.  endif
.endfor
.if ${OPSYS} == "Linux"
PKG_SUGGESTED_OPTIONS+=	vidix
.endif

# -------------------------------------------------------------------------
# Handle extra libraries (part 1)
# -------------------------------------------------------------------------
EXTRA_LIBS=

# -------------------------------------------------------------------------
# Handle chosen options.
# -------------------------------------------------------------------------

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Maalib)
.  include "../../graphics/aalib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Marts)
CONFIGURE_ARGS+=	--enable-arts
EXTRA_LIBS+=		-lartsc
.  include "../../audio/arts/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-arts
.endif

.if !empty(PKG_OPTIONS:Mcaca)
CONFIGURE_ARGS+=	--enable-caca
.  include "../../graphics/libcaca/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mcdparanoia)
CONFIGURE_ARGS+=	--enable-cdparanoia
.  include "../../audio/cdparanoia/buildlink3.mk"
CFLAGS+=		-I${BUILDLINK_PREFIX.cdparanoia}/include/cdparanoia
.else
CONFIGURE_ARGS+=	--disable-cdparanoia
.endif

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif

.if !empty(PKG_OPTIONS:Mdts)
# The configure handling for --enable-libdca is broken.
# However, it works if you omit the argument and let
# configure autodetect support.
#CONFIGURE_ARGS+=       --enable-libdca
.  include "../../audio/libdca/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-libdca
.endif

.if !empty(PKG_OPTIONS:Mdv)
CONFIGURE_ARGS+=	--enable-libdv
.  include "../../multimedia/libdv/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-libdv
.endif

CONFIGURE_ARGS+=	--disable-dvdread-internal
.if !empty(PKG_OPTIONS:Mdvdread)
CONFIGURE_ARGS+=	--enable-dvdread
CONFIGURE_ARGS+=	--with-dvdread-config=${BUILDLINK_PREFIX.libdvdread}/bin/dvdread-config
.  include "../../multimedia/libdvdread/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-dvdread
.endif

.if !empty(PKG_OPTIONS:Mdvdnav)
CONFIGURE_ARGS+=	--enable-dvdnav
CONFIGURE_ARGS+=	--with-dvdnav-config=${BUILDLINK_PREFIX.libdvdnav}/bin/dvdnav-config
.  include "../../multimedia/libdvdnav/buildlink3.mk"
#CFLAGS+=		-I${BUILDLINK_PREFIX.libdvdnav}/include/dvdnav
.else
CONFIGURE_ARGS+=	--disable-dvdnav
.endif

.if !empty(PKG_OPTIONS:Mesound)
CONFIGURE_ARGS+=	--enable-esd
.  include "../../audio/esound/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-esd
.endif

.if !empty(PKG_OPTIONS:Mfaac)
.  include "../../audio/faac/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-faac
.endif

.if empty(PKG_OPTIONS:Mfaad) && empty(PKG_OPTIONS:Mmplayer-internal-faad)
CONFIGURE_ARGS+=	--disable-faad-internal
.elif !empty(PKG_OPTIONS:Mfaad)
CONFIGURE_ARGS+=	--enable-faad
.  include "../../audio/faad2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--enable-faad-internal
.endif

.if !empty(PKG_OPTIONS:Mggi)
CONFIGURE_ARGS+=	--enable-ggi
.  include "../../graphics/libggi/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-ggi
.endif

.if !empty(PKG_OPTIONS:Mgif)
CONFIGURE_ARGS+=	--enable-gif
.  include "../../graphics/libungif/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gif
.endif

.if !empty(PKG_OPTIONS:Mjpeg)
CONFIGURE_ARGS+=	--enable-jpeg
.  include "../../mk/jpeg.buildlink3.mk"
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
#CONFIGURE_ARGS+=	--realcodecsdir="${PREFIX.realplayer-codecs}/lib/RealPlayer8-Codecs"
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
CONFIGURE_ARGS+=	--enable-win32dll
#CONFIGURE_ARGS+=	--win32codecsdir="${PREFIX.win32-codecs}/lib/win32"
DEPENDS+=		win32-codecs>=011227:../../multimedia/win32-codecs
.else
CONFIGURE_ARGS+=	--disable-win32dll
.endif

.if !empty(PKG_OPTIONS:Mnas)
CONFIGURE_ARGS+=	--enable-nas
.  include "../../audio/nas/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-nas
.endif

.if ${OSS_TYPE} != "none" && !empty(PKG_OPTIONS:Moss)
CONFIGURE_ARGS+=	--enable-ossaudio
.else
CONFIGURE_ARGS+=	--disable-ossaudio
.endif

.if !empty(PKG_OPTIONS:Mpng)
CONFIGURE_ARGS+=	--enable-png
.  include "../../graphics/png/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-png
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
CONFIGURE_ARGS+=	--enable-pulse
.  include "../../devel/glib2/buildlink3.mk"
.  include "../../audio/pulseaudio/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-pulse
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

.if !empty(PKG_OPTIONS:Mv4l2)
CONFIGURE_ARGS+=	--enable-tv-v4l2
.else
CONFIGURE_ARGS+=	--disable-tv-v4l2
.endif

# disable vidix if not in options
.if empty(PKG_OPTIONS:Mvidix)
CONFIGURE_ARGS+=	--disable-vidix
.endif

.if !empty(PKG_OPTIONS:Mvorbis)
CONFIGURE_ARGS+=	--enable-libvorbis
.else
CONFIGURE_ARGS+=	--disable-libvorbis
.endif

.if !empty(PKG_OPTIONS:Mx264)
.  include "../../multimedia/x264-devel/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-x264
.endif

.if !empty(PKG_OPTIONS:Mxvid)
CONFIGURE_ARGS+=	--enable-xvid
EXTRA_LIBS+=		-lxvidcore
.  include "../../multimedia/xvidcore/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-xvid
.endif

.if !empty(PKG_OPTIONS:Mmplayer-ssse3)
# needs a recent assembler
.include "../../devel/binutils/buildlink3.mk"
.include "../../devel/binutils/override-as.mk"
.else
CONFIGURE_ARGS+=	--disable-ssse3
.endif

.if !empty(PKG_OPTIONS:Mvdpau)
.  include "../../multimedia/libvdpau/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-vdpau
.endif

# -------------------------------------------------------------------------
# Handle extra libraries (part 1)
# -------------------------------------------------------------------------
.if ${EXTRA_LIBS} != ""
CONFIGURE_ARGS+=	--extra-libs=${EXTRA_LIBS:C/^ //:Q}
.endif

.endif # defined(PKGNAME) && empty(PKGNAME:Mmplayer-share*)
