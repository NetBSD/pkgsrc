# $NetBSD: Makefile,v 1.1 2020/03/18 01:23:01 nia Exp $

DISTNAME=	allegro-5.2.6.0
PKGNAME=	${DISTNAME:S/allegro-/allegro5-/1}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=liballeg/}
GITHUB_PROJECT=	allegro5
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://liballeg.org/
COMMENT=	Cross-platform library aimed at video game programming
LICENSE=	zlib

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-Wno-dev
CMAKE_ARGS+=	-DWANT_IMAGE_FREEIMAGE=OFF

.include "../../mk/oss.buildlink3.mk"
.if ${OSS_TYPE} != "none"
LDFLAGS+=	${LIBOSSAUDIO}
.else
CMAKE_ARGS+=	-DWANT_OSS=OFF
.endif

PKGCONFIG_OVERRIDE+=	misc/allegro.pc.in
PKGCONFIG_OVERRIDE+=	misc/allegro_acodec.pc.in
PKGCONFIG_OVERRIDE+=	misc/allegro_audio.pc.in
PKGCONFIG_OVERRIDE+=	misc/allegro_color.pc.in
PKGCONFIG_OVERRIDE+=	misc/allegro_dialog.pc.in
PKGCONFIG_OVERRIDE+=	misc/allegro_font.pc.in
PKGCONFIG_OVERRIDE+=	misc/allegro_image.pc.in
PKGCONFIG_OVERRIDE+=	misc/allegro_main.pc.in
PKGCONFIG_OVERRIDE+=	misc/allegro_memfile.pc.in
PKGCONFIG_OVERRIDE+=	misc/allegro_monolith.pc.in
PKGCONFIG_OVERRIDE+=	misc/allegro_physfs.pc.in
PKGCONFIG_OVERRIDE+=	misc/allegro_primitives.pc.in
PKGCONFIG_OVERRIDE+=	misc/allegro_ttf.pc.in
PKGCONFIG_OVERRIDE+=	misc/allegro_video.pc.in

.include "options.mk"
.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} != "Darwin"
.  include "../../graphics/MesaLib/buildlink3.mk"
.  include "../../graphics/glu/buildlink3.mk"
.  include "../../graphics/png/buildlink3.mk"
.  include "../../mk/jpeg.buildlink3.mk"
.endif
.include "../../audio/dumb/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/opusfile/buildlink3.mk"
.include "../../devel/physfs/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../net/enet/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
