# $NetBSD: Makefile,v 1.17 2004/10/03 00:14:42 tv Exp $
#

DISTNAME=		asc-source-1.14.0.0
PKGNAME=		${DISTNAME:S/-source//}
PKGREVISION=	1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=asc-hq/}
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} ${AUDIO_FILES}

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.asc-hq.org/
COMMENT=		Turn based strategy game

AUDIO_FILES=		frontiers.mp3 machine_wars.mp3 time_to_strike.mp3
EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes
CPPFLAGS.NetBSD+=		-D_UNICODE_BROKEN_

# ../weaponguide.cpp:1205: virtual memory exhausted
UNLIMIT_RESOURCES=	datasize

post-extract:
.for fil in ${AUDIO_FILES}
	${CP} ${DISTDIR}/${fil} ${WRKSRC}/data/music
.endfor

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDLmm/buildlink3.mk"
.include "../../devel/libsigc++/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../multimedia/smpeg/buildlink3.mk"
.include "../../x11/paragui/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
