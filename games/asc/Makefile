# $NetBSD: Makefile,v 1.7 2003/12/08 14:41:39 wiz Exp $
#

DISTNAME=		asc-source-1.13.8.0
PKGNAME=		${DISTNAME:S/-source//}
PKGREVISION=				1
WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=asc-hq/}
DISTFILES=		${DISTNAME}${EXTRACT_SUFX} ${AUDIO_FILES}

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.asc-hq.org/
COMMENT=		Turn based strategy game

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
