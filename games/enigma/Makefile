# $NetBSD: Makefile,v 1.1.1.1 2004/03/01 22:46:22 heinz Exp $
#

DISTNAME=		enigma-0.81
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_GNU:=enigma/} \
			http://www.rzuser.uni-heidelberg.de/~dheck/

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://www.nongnu.org/enigma/
COMMENT=		Puzzle game similar to Oxyd/Rock'n'Roll/Marble Madness

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GCC_REQD+=		2.95
GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_GNU_TOOLS+=		make
USE_LANGUAGES=		c c++

SUBST_CLASSES+=		enigma
SUBST_STAGE.enigma=	post-patch
SUBST_FILES.enigma=	doc/manual/enigma_1.html
SUBST_SED.enigma=	-e s!/usr/local/!${PREFIX}/!

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
