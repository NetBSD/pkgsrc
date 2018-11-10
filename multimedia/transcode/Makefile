# $NetBSD: Makefile,v 1.112 2018/11/10 20:50:28 wiz Exp $

DISTNAME=	transcode-1.1.7
PKGREVISION=	29
CATEGORIES=	multimedia
MASTER_SITES=	http://bitbucket.org/france/transcode-tcforge/downloads/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://bitbucket.org/achurch_/transcode/wiki/Home
# or https://bitbucket.org/france/transcode-tcforge/wiki/Home
COMMENT=	Command line video-stream processing tool
LICENSE=	gnu-gpl-v2

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		awk:run gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--enable-freetype2
CONFIGURE_ARGS+=	--enable-libmpeg2
CONFIGURE_ARGS+=	--enable-libmpeg2convert
CONFIGURE_ARGS+=	--enable-libpostproc
CONFIGURE_ARGS+=	--enable-ogg
CONFIGURE_ARGS+=	--enable-theora
CONFIGURE_ARGS+=	--enable-vorbis
CONFIGURE_ARGS+=	--enable-xvid
CONFIGURE_ENV+=		PATH_TO_AWK=${AWK:Q}

PTHREAD_AUTO_VARS=	yes
PTHREAD_OPTS=		require

.include "../../mk/bsd.prefs.mk"

PLIST_VARS+=		i386 oss x11

.if ${MACHINE_ARCH} == "i386"
PLIST.i386=		yes
.endif

.if ${OPSYS} != "Darwin"
CONFIGURE_ARGS+=	--enable-oss
PLIST.oss=		yes
PLIST.x11=		yes
LIBS+=			${LIBOSSAUDIO}
.endif

.include "options.mk"

.include "../../audio/lame/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/ffmpeg2/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../multimedia/libmpeg2/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../multimedia/xvidcore/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.endif
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
