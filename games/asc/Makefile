# $NetBSD: Makefile,v 1.1.1.1 2003/07/13 22:23:13 wiz Exp $
#

DISTNAME=		asc-source-1.13.7
PKGNAME=		${DISTNAME:S/-source//}
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=asc-hq/}
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} ${AUDIO_FILES}

MAINTAINER=		wiz@netbsd.org
HOMEPAGE=		http://asc-hq.sourceforge.net/
COMMENT=		turn based strategy game

AUDIO_FILES=		frontiers.mp3 machine_wars.mp3 time_to_strike.mp3
EXTRACT_ONLY=		${DISTNAME}${EXTRACT_SUFX}

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_GMAKE=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
GNU_CONFIGURE=		yes

# ../weaponguide.cpp:1205: virtual memory exhausted
UNLIMIT_RESOURCES=	datasize

post-extract:
.for fil in ${AUDIO_FILES}
	${CP} ${DISTDIR}/${fil} ${WRKSRC}/data/music
.endfor

.include "../../audio/SDL_mixer/buildlink2.mk"
.include "../../devel/SDLmm/buildlink2.mk"
.include "../../devel/smpeg/buildlink2.mk"
.include "../../graphics/SDL_image/buildlink2.mk"
.include "../../x11/paragui/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
