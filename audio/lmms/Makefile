# $NetBSD: Makefile,v 1.20 2012/09/12 00:24:45 asau Exp $
#

DISTNAME=		lmms-0.2.0
PKGREVISION=		12
CATEGORIES=		audio
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=lmms/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://lmms.sourceforge.net/
COMMENT=		Linux MultiMedia Studio

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake perl

BUILDLINK_TRANSFORM+=	rm:-floop-optimize2 rm:-fgcse-las

# libSDL defines some symbols that are also defined in libX11, which has
# been fixed in SDL 1.2.11.
BUILDLINK_ABI_DEPENDS.SDL+=	SDL>=1.2.11

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../audio/SDL_sound/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/jack/buildlink3.mk"
.include "../../audio/libsamplerate/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../x11/libXfixes/buildlink3.mk"
.include "../../x11/qt3-libs/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
