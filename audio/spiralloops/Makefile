# $NetBSD: Makefile,v 1.5 2003/07/19 08:54:27 wiz Exp $
#

DISTNAME=		SpiralLoops-2.0.0
PKGNAME=		spiralloops-2.0.0
CATEGORIES=		audio
MASTER_SITES=		http://www.pawfal.org/SpiralLoops/dload/

MAINTAINER=		collver1@comcast.net
HOMEPAGE=		http://www.pawfal.org/SpiralLoops/
COMMENT=		loop based sampler

# only runs correctly on little-endian machines
ONLY_FOR_PLATFORM=	*-*-alpha *-*-arc *-*-cobalt *-*-dreamcast \
			*-*-hpcmips *-*-hpcsh *-*-i386 *-*-pc532 *-*-pmax \
			*-*-vax

USE_BUILDLINK2=		yes
USE_X11=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/SpiralLoops ${PREFIX}/bin

.include "../../x11/fltk/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
