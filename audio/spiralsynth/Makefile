# $NetBSD: Makefile,v 1.2 2002/06/12 00:07:35 wiz Exp $
#

DISTNAME=		SpiralSynth-0.1.7
PKGNAME=		spiralsynth-0.1.7
CATEGORIES=		audio
MASTER_SITES=		http://www.pawfal.org/Software/SpiralSynth/dload/

MAINTAINER=		collver@linuxfreemail.com
HOMEPAGE=		http://www.pawfal.org/Software/SpiralSynth/
COMMENT=		polyphonic analogue softsynth

# only runs correctly on little-endian machines
ONLY_FOR_PLATFORM=	*-*-alpha *-*-arc *-*-cobalt *-*-dreamcast \
			*-*-hpcmips *-*-hpcsh *-*-i386 *-*-pc532 *-*-pmax \
			*-*-vax

USE_GMAKE=		yes
GNU_CONFIGURE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/SpiralSynth ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/spiralsynth
	${INSTALL_DATA} ${WRKSRC}/.SpiralPatches.bank \
		${WRKSRC}/.Spiralrc ${PREFIX}/share/spiralsynth

.include "../../x11/fltk/buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
