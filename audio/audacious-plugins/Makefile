# $NetBSD: Makefile,v 1.103 2020/04/12 08:28:17 adam Exp $

DISTNAME=	audacious-plugins-4.0
PKGREVISION=	1
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
CONFIGURE_ARGS+=	--disable-notify
# use SDL instead, it has working volume control
CONFIGURE_ARGS+=	--disable-oss4
CONFIGURE_ARGS+=	--disable-qtaudio
CONFIGURE_ARGS+=	--disable-sndio

PLIST_VARS+=	dbus

.include "options.mk"
.include "../../audio/audacious/buildlink3.mk"
.if !empty(PKG_BUILD_OPTIONS.audacious:Mdbus)
TOOL_DEPENDS+=	gdbus-codegen-[0-9]*:../../devel/gdbus-codegen
PLIST.dbus=		yes
.else
CONFIGURE_ARGS+=	--disable-mpris2
.endif
.include "../../audio/faad2/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libcddb/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libsoxr/buildlink3.mk"
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
