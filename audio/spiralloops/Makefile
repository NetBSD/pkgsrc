# $NetBSD: Makefile,v 1.1.1.1 2001/08/12 22:27:05 zuntum Exp $
#

DISTNAME=		SpiralLoops-2.0.0
PKGNAME=		spiralloops-2.0.0
CATEGORIES=		audio
MASTER_SITES=		http://www.pawfal.org/SpiralLoops/dload/

MAINTAINER=		collver@linuxfreemail.com
HOMEPAGE=		http://www.pawfal.org/SpiralLoops/
COMMENT=		loop based sampler

# only runs correctly on little-endian machines
ONLY_FOR_PLATFORM=	*-*-alpha *-*-arc *-*-cobalt *-*-dreamcast \
			*-*-hpcmips *-*-hpcsh *-*-i386 *-*-pc532 *-*-pmax \
			*-*-vax

USE_X11=		yes
USE_GMAKE=		yes
GNU_CONFIGURE=		yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/SpiralLoops ${PREFIX}/bin

.include "../../x11/fltk/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
