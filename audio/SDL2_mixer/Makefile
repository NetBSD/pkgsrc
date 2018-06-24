# $NetBSD: Makefile,v 1.6 2018/06/24 10:28:45 adam Exp $

DISTNAME=	SDL2_mixer-2.0.2
CATEGORIES=	audio devel
MASTER_SITES=	http://www.libsdl.org/projects/SDL_mixer/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.libsdl.org/projects/SDL_mixer/
COMMENT=	Sample multi-channel audio mixer library
LICENSE=	zlib

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	SDL2_mixer.pc.in
PKGCONFIG_OVERRIDE+=	external/flac-1.2.1/src/libFLAC/flac.pc.in
PKGCONFIG_OVERRIDE+=	external/flac-1.2.1/src/libFLAC++/flac++.pc.in
PKGCONFIG_OVERRIDE+=	external/libmodplug-0.8.8.4/libmodplug.pc.in
PKGCONFIG_OVERRIDE+=	external/libogg-1.3.1/ogg.pc.in
PKGCONFIG_OVERRIDE+=	external/libvorbis-1.3.3/vorbis.pc.in
PKGCONFIG_OVERRIDE+=	external/libvorbis-1.3.3/vorbisenc.pc.in
PKGCONFIG_OVERRIDE+=	external/libvorbis-1.3.3/vorbisfile.pc.in
PKGCONFIG_OVERRIDE+=	external/libvorbisidec-1.2.1/vorbisidec.pc.in

.include "options.mk"

.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
