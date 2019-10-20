# $NetBSD: Makefile,v 1.125 2019/10/20 09:59:13 nia Exp $

DISTNAME=		audacity-2.3.2
PKGREVISION=		1
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_GITHUB:=audacity/}
GITHUB_PROJECT=		Audacity
GITHUB_TAG=		Audacity-${PKGVERSION_NOREV}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.audacityteam.org/
COMMENT=		Audio editor
LICENSE=		gnu-gpl-v2 # AND cc-by-v3.0-license

WRKSRC=			${WRKDIR}/audacity-${GITHUB_PROJECT}-${PKGVERSION_NOREV}

.include "../../mk/bsd.prefs.mk"

EXTRACT_USING=		bsdtar
USE_LIBTOOL=		yes
USE_TOOLS+=		automake autoreconf bash
USE_TOOLS+=		gmake intltool msgfmt msgmerge pkg-config
USE_TOOLS+=		xgettext zip:run
USE_LANGUAGES=		c c++
# configure: error: Audacity requires at least GCC 4.9
GCC_REQD+=		4.9

WRAPPER_SHELL=		${BASH}
CONFIG_SHELL=		${BASH}

GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-nyquist=yes
CONFIGURE_ARGS+=	--with-expat=system
CONFIGURE_ARGS+=	--with-ffmpeg=system
CONFIGURE_ARGS+=	--with-lame=system
CONFIGURE_ARGS+=	--with-libflac=system
CONFIGURE_ARGS+=	--with-libid3tag=system
CONFIGURE_ARGS+=	--with-libsamplerate=system
CONFIGURE_ARGS+=	--with-libsndfile=system
CONFIGURE_ARGS+=	--with-libtwolame=system
CONFIGURE_ARGS+=	--with-libvamp=local
CONFIGURE_ARGS+=	--with-libvorbis=system
CONFIGURE_ARGS+=	--with-lv2=system
CONFIGURE_ARGS+=	--with-midi=local
# configure: error: Your version of portaudio does not include
# required Pa_GetStreamHostApiType function
CONFIGURE_ARGS+=	--with-portaudio=local
CONFIGURE_ARGS+=	--with-sbsms=local
CONFIGURE_ARGS+=	--with-soundtouch=system
CONFIGURE_ARGS+=	--with-libsoxr=system
CONFIGURE_ARGS+=	--with-widgetextra=local

# for internal portaudio...
.if ${OPSYS} == "Linux"
CONFIGURE_ARGS+=	--with-alsa
.else
CONFIGURE_ARGS+=	--without-alsa
CONFIGURE_ENV+=		ac_cv_header_pa_linux_alsa_h=no
.endif

.if ${MACHINE_ARCH} == "i386"
# 64 bit atomic ops are required
CXXFLAGS+=	-march=i586
.endif

.if ${MACHINE_ARCH} != "i386" && ${MACHINE_ARCH} != "x86_64"
CONFIGURE_ARGS+=	--disable-sse
.endif

.include "../../mk/oss.buildlink3.mk"

.if !empty(OSS_TYPE) && ${OSS_TYPE} != "none"
CONFIGURE_ARGS+=	--with-oss
.else
CONFIGURE_ARGS+=	--without-oss
.endif

CONFIG_GUESS_OVERRIDE= \
	config.guess */config.guess */*/config.guess */*/*/config.guess
CONFIG_SUB_OVERRIDE= \
	config.sub */config.sub */*/config.sub */*/*/config.sub

CFLAGS.SunOS+=	-fPIC

PTHREAD_AUTO_VARS=	yes
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
BUILDLINK_TRANSFORM+=	rm:-Wl,--version-script=./build/vamp-plugin.map

LIBS.NetBSD+=	-lcompat

INSTALLATION_DIRS+=	lib

# regen Makefile.in to avoid being built as shared libraries
pre-configure:
	cd ${WRKSRC}/lib-src/portaudio-v19 && ${PKGSRC_SETENV} autoreconf -fiv
	cd ${WRKSRC}/lib-src/portmixer && ${PKGSRC_SETENV} autoreconf -fiv
	cd ${WRKSRC}/lib-src/lib-widget-extra && autoreconf -fiv

post-install:
	${INSTALL_LIB} ${WRKSRC}/lib-src/FileDialog/.libs/libFileDialog.so.0.0.0 \
		${DESTDIR}${PREFIX}/lib/libFileDialog.so.0

.include "options.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../audio/alsa-lib/buildlink3.mk"
.include "../../audio/lilv/buildlink3.mk"
.include "../../audio/lv2/buildlink3.mk"
.include "../../audio/soundtouch/buildlink3.mk"
BUILDLINK_API_DEPENDS.twolame+=	twolame>=0.3.9
.include "../../audio/twolame/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsoxr/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/suil/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.flac+=	flac>=1.3.0
.include "../../audio/flac/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
