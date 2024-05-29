# $NetBSD: Makefile,v 1.155 2024/05/29 16:31:18 adam Exp $

DISTNAME=	audacious-plugins-4.1
PKGREVISION=	35
CATEGORIES=	audio
MASTER_SITES=	https://distfiles.audacious-media-player.org/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://audacious-media-player.org/
COMMENT=	Plugins for Audacious media player
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake intltool pkg-config
USE_TOOLS+=	msgfmt msgmerge xgettext
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--disable-ampache
CONFIGURE_ARGS+=	--disable-bs2b
CONFIGURE_ARGS+=	--disable-cue
# prefer libsamplerate
CONFIGURE_ARGS+=	--disable-soxr
CONFIGURE_ARGS+=	--disable-notify
CONFIGURE_ARGS+=	--disable-qtaudio
CONFIGURE_ARGS+=	--disable-sndio

.include "../../mk/oss.buildlink3.mk"
PLIST_VARS+=		oss4
# Currently, don't use this on NetBSD - the volume manipulation is broken.
# Use SDL instead, it has working volume control
.if ${OSS_TYPE} != "none" && \
	(${OPSYS} == "FreeBSD" || \
	${OPSYS} == "SunOS")
PLIST.oss4=		yes
LDFLAGS+=		${LIBOSSAUDIO}
SUBST_CLASSES+=		oss
SUBST_STAGE.oss=	pre-configure
SUBST_MESSAGE.oss=	Correcting the path to the OSS device.
SUBST_FILES.oss+=	src/oss4/oss.h
SUBST_SED.oss+=		-e "s,/dev/dsp,${DEVOSSAUDIO},g"
.else
CONFIGURE_ARGS+=	--disable-oss4
.endif

.include "../../audio/audacious/buildlink3.mk"

PLIST_VARS+=		gtk2
.if ${PKG_BUILD_OPTIONS.audacious:Mgtk2}
PLIST.gtk2+=		yes
.else
CONFIGURE_ARGS+=	--disable-gtk
.endif

PLIST_VARS+=		qt5
.if ${PKG_BUILD_OPTIONS.audacious:Mqt5}
PLIST.qt5=		yes
.else
CONFIGURE_ARGS+=	--disable-qt
.endif

PLIST_VARS+=	dbus
.if ${PKG_BUILD_OPTIONS.audacious:Mdbus}
USE_TOOLS+=		gdbus-codegen
PLIST.dbus=		yes
.else
CONFIGURE_ARGS+=	--disable-mpris2
.endif

.include "options.mk"
.include "../../audio/faad2/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libcddb/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/libbinio/buildlink3.mk"
.include "../../misc/libcdio-paranoia/buildlink3.mk"
.include "../../multimedia/ffmpeg4/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../net/libmms/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../www/neon/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
