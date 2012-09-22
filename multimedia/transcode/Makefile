# $NetBSD: Makefile,v 1.77 2012/09/22 13:48:19 ryoon Exp $

DISTNAME=	transcode-1.1.5
PKGREVISION=	15
CATEGORIES=	multimedia
MASTER_SITES=	http://download.berlios.de/tcforge/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://tcforge.berlios.de/
COMMENT=	Command line video-stream processing tool

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		awk:run gmake pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-xio
CONFIGURE_ARGS+=	--enable-libmpeg2
CONFIGURE_ARGS+=	--enable-libmpeg2convert
CONFIGURE_ARGS+=	--enable-libpostproc
CONFIGURE_ARGS+=	--enable-ogg
CONFIGURE_ARGS+=	--enable-theora
CONFIGURE_ARGS+=	--enable-vorbis
CONFIGURE_ARGS+=	--enable-xvid
CONFIGURE_ARGS+=	--with-libavcodec-prefix=${BUILDLINK_PREFIX.ffmpeg}
CONFIGURE_ENV+=		PATH_TO_AWK=${AWK:Q}

PTHREAD_AUTO_VARS=	yes
PTHREAD_OPTS=		require

.include "../../mk/bsd.prefs.mk"

.if ${MACHINE_ARCH} == "i386"
PLIST.i386=		yes
.endif

PLIST_VARS+=		i386 oss x11

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
.include "../../multimedia/ffmpeg/buildlink3.mk"
.include "../../multimedia/libdvdread/buildlink3.mk"
.include "../../multimedia/libmpeg2/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.if ${OPSYS} != "Darwin"
.include "../../x11/libXaw/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXv/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.endif
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
