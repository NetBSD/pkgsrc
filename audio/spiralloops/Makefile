# $NetBSD: Makefile,v 1.24 2005/12/05 20:49:49 rillig Exp $
#

DISTNAME=		SpiralLoops-2.0.0
PKGNAME=		spiralloops-2.0.0
PKGREVISION=		2
CATEGORIES=		audio
MASTER_SITES=		http://www.pawfal.org/Software/SpiralLoops/dload/

MAINTAINER=		ben@NetBSD.org
HOMEPAGE=		http://www.pawfal.org/Software/SpiralLoops/
COMMENT=		Loop based sampler

# only runs correctly on little-endian machines
ONLY_FOR_PLATFORM=	*-*-alpha *-*-arc *-*-cobalt *-*-dreamcast \
			*-*-hpcmips *-*-hpcsh *-*-i386 *-*-pc532 *-*-pmax \
			*-*-vax

USE_LANGUAGES=		c++
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
MAKE_ENV+=		CXXFLAGS=${CXXFLAGS:M*:Q}
CXXFLAGS+=		-DDEVOSSAUDIO="\"${DEVOSSAUDIO}\""
CXXFLAGS+=		-DFLTK_1_0_COMPAT

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/SpiralLoops ${PREFIX}/bin

.include "../../x11/fltk/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
