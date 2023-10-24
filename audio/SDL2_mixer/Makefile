# $NetBSD: Makefile,v 1.22 2023/10/24 22:08:09 wiz Exp $

DISTNAME=	SDL2_mixer-2.0.4
PKGREVISION=	13
CATEGORIES=	audio devel
MASTER_SITES=	http://www.libsdl.org/projects/SDL_mixer/release/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.libsdl.org/projects/SDL_mixer/
COMMENT=	Sample multi-channel audio mixer library
LICENSE=	zlib

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		gmake pkg-config
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	SDL2_mixer.pc.in

.include "options.mk"

.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libmodplug/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../audio/opusfile/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
