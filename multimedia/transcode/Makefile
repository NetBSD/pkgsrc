# $NetBSD: Makefile,v 1.39 2007/04/17 18:51:45 xtraeme Exp $
#

DISTNAME=	transcode-1.0.3
#PKGREVISION=	1
CATEGORIES=	multimedia
MASTER_SITES=	http://fromani.exit1.org/ \
		http://dl.fkb.wormulon.net/transcode/ \
		http://dl.kel.wormulon.net/transcode/ \
		http://kraymer.de/mirroring/ \
		http://www.jakemsr.com/transcode/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://www.transcoding.org/
COMMENT=	Command line video-stream processing tool

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	awk:run gmake pkg-config
USE_LANGUAGES=	c c++

CONFIGURE_ENV+=		PATH_TO_AWK=${AWK:Q}
CONFIGURE_ARGS+=	--disable-libpostproc
CONFIGURE_ARGS+=	--with-libavcodec-prefix=${BUILDLINK_PREFIX.ffmpeg}
CONFIGURE_ARGS+=	--enable-oss
CONFIGURE_ARGS+=	--disable-xio

LIBS+=			${LIBOSSAUDIO}

.include "../../mk/compiler.mk"

.if !empty(CC_VERSION:Mgcc-4*)
PLIST_SUBST+=		TOMSMOCOMP='@comment '
.else
PLIST_SUBST+=		TOMSMOCOMP=
.endif

.include "options.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../multimedia/libmpeg2/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
