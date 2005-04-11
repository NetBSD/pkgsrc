# $NetBSD: Makefile,v 1.18 2005/04/11 21:44:57 tv Exp $
#

DISTNAME=		SpiralLoops-2.0.0
PKGNAME=		spiralloops-2.0.0
PKGREVISION=		2
CATEGORIES=		audio
MASTER_SITES=		http://www.pawfal.org/SpiralLoops/dload/

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://www.pawfal.org/SpiralLoops/
COMMENT=		Loop based sampler

# only runs correctly on little-endian machines
ONLY_FOR_PLATFORM=	*-*-alpha *-*-arc *-*-cobalt *-*-dreamcast \
			*-*-hpcmips *-*-hpcsh *-*-i386 *-*-pc532 *-*-pmax \
			*-*-vax

USE_LANGUAGES=		c++
USE_X11=		yes
USE_GNU_TOOLS+=		make
GNU_CONFIGURE=		yes
MAKE_ENV+=		CXXFLAGS="${CXXFLAGS}"
CXXFLAGS+=		-DDEVOSSAUDIO="\"${DEVOSSAUDIO}\""
CXXFLAGS+=		-DFLTK_1_0_COMPAT

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/SpiralLoops ${PREFIX}/bin

.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
