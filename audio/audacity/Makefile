# $NetBSD: Makefile,v 1.156 2024/01/22 13:16:54 ryoon Exp $

# NOTES ON UPDATING
# - Upstream is insisting that packages use their internal modified
#   versions of libraries like wxWidgets. This goes against policy
#   of not using vendored libraries.
# - Upstream is introducing telemetry.
#   This should be disabled by default, Audacity is offline software.
# - Please test usage on NetBSD.
DISTNAME=	audacity-2.4.1
PKGREVISION=	18
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_GITHUB:=audacity/}
GITHUB_PROJECT=	Audacity
GITHUB_TAG=	Audacity-${PKGVERSION_NOREV}

MAINTAINER=	nia@NetBSD.org
HOMEPAGE=	https://www.audacityteam.org/
COMMENT=	Multi-track audio editor and recorder
LICENSE=	gnu-gpl-v2 # AND cc-by-v3.0-license

WRKSRC=		${WRKDIR}/audacity-${GITHUB_PROJECT}-${PKGVERSION_NOREV}

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

USE_TOOLS+=	automake autoreconf bash
USE_TOOLS+=	gmake intltool msgfmt msgmerge pkg-config
USE_TOOLS+=	xgettext zip:run

USE_LANGUAGES=	c c++

# configure: error: Audacity requires at least GCC 4.9
GCC_REQD+=	4.9

WRAPPER_SHELL=	${BASH}
CONFIG_SHELL=	${BASH}

CONFIGURE_ARGS+=	--enable-ladspa

CONFIGURE_ARGS+=	--with-libmad="no"
CONFIGURE_ARGS+=	--with-expat="system"
CONFIGURE_ARGS+=	--with-libsndfile="system"
CONFIGURE_ARGS+=	--with-libsoxr="system"
CONFIGURE_ARGS+=	--with-portaudio="system"
CONFIGURE_ARGS+=	--with-sbsms="local" # system version doesn't work
CONFIGURE_ARGS+=	--with-midi="no"
CONFIGURE_ARGS+=	--with-portmidi="no"
CONFIGURE_ARGS+=	--with-ffmpeg="system"
CONFIGURE_ARGS+=	--with-lame="system"
CONFIGURE_ARGS+=	--with-libflac="system"
CONFIGURE_ARGS+=	--with-libid3tag="system"
CONFIGURE_ARGS+=	--with-libtwolame="system"
CONFIGURE_ARGS+=	--with-libvamp="system"
CONFIGURE_ARGS+=	--with-libvorbis="system"
CONFIGURE_ARGS+=	--with-lv2="system"
CONFIGURE_ARGS+=	--with-soundtouch="system"

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} != "i386" && ${MACHINE_ARCH} != "x86_64"
CONFIGURE_ARGS+=	--disable-sse
.endif

CFLAGS.SunOS+=		-fPIC

LIBS.NetBSD+=		-lcompat

CONFIG_GUESS_OVERRIDE= \
	config.guess */config.guess */*/config.guess */*/*/config.guess
CONFIG_SUB_OVERRIDE= \
	config.sub */config.sub */*/config.sub */*/*/config.sub

PTHREAD_AUTO_VARS=	yes

INSTALLATION_DIRS+=	lib
INSTALLATION_DIRS+=	share/audacity/plug-ins

# regen Makefile.in to avoid being built as shared libraries
pre-configure:
	cd ${WRKSRC}/lib-src/portmixer && ${PKGSRC_SETENV} autoreconf -fiv
	cd ${WRKSRC}/lib-src/lib-widget-extra && autoreconf -fiv

post-install:
	${INSTALL_LIB} ${WRKSRC}/lib-src/FileDialog/.libs/libFileDialog.so.0.0.0 \
		${DESTDIR}${PREFIX}/lib/libFileDialog.so.0
	# Install missing plugins.
	${INSTALL_DATA} ${WRKSRC}/plug-ins/*.ny \
		${DESTDIR}${PREFIX}/share/audacity/plug-ins
	${INSTALL_DATA} ${WRKSRC}/nyquist/*.lsp \
		${DESTDIR}${PREFIX}/share/audacity/nyquist

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../audio/lilv/buildlink3.mk"
.include "../../audio/lv2/buildlink3.mk"
.include "../../audio/soundtouch/buildlink3.mk"
BUILDLINK_API_DEPENDS.twolame+=	twolame>=0.3.9
.include "../../audio/twolame/buildlink3.mk"
.include "../../audio/ladspa/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libsoxr/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
BUILDLINK_API_DEPENDS.portaudio+=	portaudio>=190600.20161030nb2
.include "../../audio/portaudio/buildlink3.mk"
.include "../../audio/suil/buildlink3.mk"
.include "../../audio/vamp-plugin-sdk/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.flac+=	flac>=1.3.0
.include "../../audio/flac/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/wxGTK30/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:Q}
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
