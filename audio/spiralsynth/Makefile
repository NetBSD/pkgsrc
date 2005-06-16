# $NetBSD: Makefile,v 1.20 2005/06/16 06:57:39 jlam Exp $
#

DISTNAME=		SpiralSynth-2.0.0
PKGNAME=		spiralsynth-2.0.0
CATEGORIES=		audio
MASTER_SITES=		http://www.pawfal.org/Software/SpiralSynth/dload/

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://www.pawfal.org/Software/SpiralSynth/
COMMENT=		Polyphonic analogue softsynth

# only runs correctly on little-endian machines
ONLY_FOR_PLATFORM=	*-*-alpha *-*-arc *-*-cobalt *-*-dreamcast \
			*-*-hpcmips *-*-hpcsh *-*-i386 *-*-pc532 *-*-pmax \
			*-*-vax

USE_LANGUAGES=		c++
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
MAKE_ENV+=		CXXFLAGS="${CXXFLAGS}"
CXXFLAGS+=		-DDEVOSSAUDIO="\"${DEVOSSAUDIO}\""

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/SpiralSynth ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/spiralsynth
	${INSTALL_DATA} ${WRKSRC}/.SpiralPatches.bank \
		${WRKSRC}/.Spiralrc ${PREFIX}/share/spiralsynth

.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
