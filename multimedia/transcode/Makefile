# $NetBSD: Makefile,v 1.19 2006/01/24 05:33:21 xtraeme Exp $
#

DISTNAME=	transcode-1.0.2
CATEGORIES=	multimedia
MASTER_SITES=	http://dl.fkb.wormulon.net/transcode/ \
		http://dl.kel.wormulon.net/transcode/ \
		http://kraymer.de/mirroring/ \
		http://www.jakemsr.com/transcode/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.transcoding.org/
COMMENT=	Command line video-stream processing tool

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

CONFIGURE_ARGS+=	--disable-libpostproc
CONFIGURE_ARGS+=	--with-libavcodec-prefix=${BUILDLINK_PREFIX.ffmpeg-devel}
CONFIGURE_ARGS+=	--enable-oss
CONFIGURE_ARGS+=	--disable-xio

LIBS+=			${LIBOSSAUDIO}

.include "options.mk"
.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/ffmpeg-devel/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../multimedia/libmpeg2/buildlink3.mk"
.include "../../multimedia/libdvdcss/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
