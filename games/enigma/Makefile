# $NetBSD: Makefile,v 1.11 2005/08/22 15:35:37 adam Exp $

DISTNAME=	enigma-0.92
CATEGORIES=	games
MASTER_SITES=	http://savannah.nongnu.org/download/enigma/

MAINTAINER=	heinz@NetBSD.org
HOMEPAGE=	http://www.nongnu.org/enigma/
COMMENT=	Puzzle game similar to Oxyd/Rock'n'Roll/Marble Madness

PKG_INSTALLATION_TYPES=	overwrite pkgviews

GCC_REQD+=		2.95
USE_DIRS+=		xdg-1.1
USE_LANGUAGES=		c c++
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

SUBST_CLASSES+=		enigma
SUBST_STAGE.enigma=	post-patch
SUBST_FILES.enigma=	doc/manual/enigma_1.html
SUBST_SED.enigma=	-e s!/usr/local/!${PREFIX}/!

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
