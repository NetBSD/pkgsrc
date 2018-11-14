# $NetBSD: Makefile,v 1.89 2018/11/14 22:20:59 kleink Exp $

DISTNAME=	audacious-plugins-3.5.2
PKGREVISION=	26
CATEGORIES=	audio
MASTER_SITES=	http://distfiles.audacious-media-player.org/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://audacious-media-player.org/
COMMENT=	Plugins for Audacious media player
LICENSE=	2-clause-bsd

TOOL_DEPENDS+=	gdbus-codegen-[0-9]*:../../devel/gdbus-codegen

USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake intltool pkg-config msgfmt
GNU_CONFIGURE=		yes
#CONFIGURE_ARGS+=	--disable-aac
CONFIGURE_ARGS+=	--disable-amidiplug
CONFIGURE_ARGS+=	--disable-evdevplug
#CONFIGURE_ARGS+=	--disable-coreaudio
CONFIGURE_ARGS+=	--disable-gnomeshortcuts
CONFIGURE_ARGS+=	--disable-modplug
CONFIGURE_ARGS+=	--disable-projectm
CONFIGURE_ARGS+=	--with-ffmpeg=none

.include "../../mk/compiler.mk"
.if empty(PKGSRC_COMPILER:Mclang)
# This should avoid an error like: libstdc++.so.6: Undefined PLT symbol "_Unwind_GetIP" on NetBSD i386 and maybe amd64, with gcc4 at least.
# This seems to happen when libstdc++ gets linked in with the plug-ins and the code is not compiled with g++.
# For a similar problem see http://archive.netbsd.se/?ml=netbsd-java&a=2007-08&m=4912662 :
# Systems with Clang are supposed to be new enough to have a correctly linked
# libstdc++.
LDFLAGS.NetBSD+=	-lgcc_s
.endif

# From audio/bmp/Makefile:
# XXX Workaround a crash during shutdown that happens when dlclose(3)ing
# any open plugin.  libstdc++ gets dynamically linked in when the id3lib
# library is loaded, and is the one causing problems.  See PR pkg/26846
# for more information.
LDFLAGS.NetBSD+=	-lstdc++ -lm

# cdaudio plugin complains about missing OSS at runtime
LDFLAGS+=		${LIBOSSAUDIO}

# do not use pkgsrc' flac if it is installed
CFLAGS+=	-I. -I../flacng -Ilibflacng

.include "../../mk/bsd.prefs.mk"
.include "options.mk"

PLIST_VARS+=	oss sun oss4

.if ${OPSYS} == "NetBSD"
RAWPART_cmd=		/sbin/sysctl -n kern.rawpartition | ${TR} 0-9 a-j
CONFIGURE_ARGS+=	--with-dev-dsp=${DEVOSSSOUND}			\
			--with-cdda-device=/dev/rcd0${RAWPART_cmd:sh}	\
			--with-cdda-dir=/cdrom/
PLIST.oss=	yes
PLIST.sun=	yes
.elif ${OPSYS} == "FreeBSD"
PLIST.oss=	yes
.elif ${OPSYS} == "DragonFly"
PLIST.oss=	yes
.elif ${OPSYS} == "SunOS"
CPPFLAGS.SunOS=	-D__EXTENSIONS__ -D__uint32_t=uint32_t -D__uint64_t=uint64_t
CONFIGURE_ARGS+=	--enable-oss4
PLIST.oss4=	yes
PLIST.oss=	yes
#.elif ${OPSYS} == "Linux"
#.  include	"../../wip/alsa-lib/buildlink3.mk"
#PKG_SUPPORTED_OPTIONS+= lirc
#.  if !empty(PKG_OPTIONS:Mlirc)
#CONFIGURE_ARGS+=	--enable-lirc
#.    include "../../wip/lirc/buildlink3.mk"
#.  endif
.endif

.include "../../audio/audacious/buildlink3.mk"
.include "../../audio/faad2/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libcddb/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libmpcdec/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../audio/taglib/buildlink3.mk"
.include "../../audio/wavpack/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/libbinio/buildlink3.mk"
.include "../../graphics/imlib2/buildlink3.mk"
.include "../../misc/libcdio-paranoia/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../net/libmms/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../www/neon/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
