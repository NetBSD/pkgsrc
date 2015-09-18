# $NetBSD: Makefile,v 1.95 2015/09/18 08:53:21 wiz Exp $

DISTNAME=		audacity-minsrc-2.1.0
PKGNAME=		${DISTNAME:S/-minsrc//1}
PKGREVISION=		3
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=audacity/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://audacityteam.org/
COMMENT=		Audio editor
LICENSE=		gnu-gpl-v2 # AND cc-by-v3.0-license

USE_LIBTOOL=		yes
USE_TOOLS+=		gmake intltool msgfmt msgmerge pkg-config
USE_TOOLS+=		xgettext zip:run
USE_LANGUAGES=		c c++
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-nyquist=yes
CONFIGURE_ARGS+=	--with-expat=system
CONFIGURE_ARGS+=	--with-ffmpeg=system
CONFIGURE_ARGS+=	--with-id3tag=system
CONFIGURE_ARGS+=	--with-libflac=system
CONFIGURE_ARGS+=	--with-libmad=system
CONFIGURE_ARGS+=	--with-libsamplerate=system
CONFIGURE_ARGS+=	--with-libsndfile=system
CONFIGURE_ARGS+=	--with-lv2=system
CONFIGURE_ARGS+=	--with-midi=local
CONFIGURE_ARGS+=	--with-portaudio=local
CONFIGURE_ARGS+=	--with-sbsms=system
CONFIGURE_ARGS+=	--with-soundtouch=system
CONFIGURE_ARGS+=	--with-twolame=system
CONFIGURE_ARGS+=	--with-vorbis=system
CONFIGURE_ARGS+=	--without-xaudio

CONFIG_GUESS_OVERRIDE=		\
	config.guess */config.guess */*/config.guess */*/*/config.guess
CONFIG_SUB_OVERRIDE=		\
	config.sub */config.sub */*/config.sub */*/*/config.sub

PTHREAD_AUTO_VARS=	yes
BUILDLINK_TRANSFORM+=	opt:-ldl:${BUILDLINK_LDADD.dl:M*}

.include "options.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../audio/lilv/buildlink3.mk"
.include "../../audio/lv2/buildlink3.mk"
.include "../../audio/soundtouch/buildlink3.mk"
BUILDLINK_API_DEPENDS.twolame+=	twolame>=0.3.9
.include "../../audio/twolame/buildlink3.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libid3tag/buildlink3.mk"
.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libsbsms/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
#.include "../../audio/portaudio-devel/buildlink3.mk" # Needs Pa_GetStreamHostApiType
.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.flac+=	flac>=1.3.0
.include "../../audio/flac/buildlink3.mk"
.include "../../multimedia/ffmpeg1/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/wxGTK28/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
