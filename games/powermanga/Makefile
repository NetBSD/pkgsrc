# $NetBSD: Makefile,v 1.32 2020/05/21 11:22:43 nia Exp $

DISTNAME=	powermanga-0.93.1
CATEGORIES=	games
MASTER_SITES=	http://linux.tlk.fr/games/Powermanga/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://linux.tlk.fr/games/Powermanga/
COMMENT=	Arcade 2D shoot-em-up game
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	autoconf automake autoreconf

CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
MAKE_ENV+=		TOUCH=${TOUCH:Q} WRKSRC=${WRKSRC}
LDFLAGS.DragonFly=	-lm
LDFLAGS.SunOS+=		-lm

SUBST_CLASSES+=		path
SUBST_STAGE.path=	pre-configure
SUBST_SED.path+=	-e "s,/games/powermanga,/powermanga,g"
SUBST_MESSAGE.path=	Fixing support file installation paths.
SUBST_FILES.path+=	data/levels/grids_phase/Makefile.am
SUBST_FILES.path+=	data/levels/curves_phase/Makefile.am
SUBST_FILES.path+=	data/Makefile.am
SUBST_FILES.path+=	data/curves/Makefile.am
SUBST_FILES.path+=	texts/Makefile.am
SUBST_FILES.path+=	graphics/bitmap/fonts/Makefile.am
SUBST_FILES.path+=	graphics/bitmap/Makefile.am
SUBST_FILES.path+=	graphics/sprites/guardians/Makefile.am
SUBST_FILES.path+=	graphics/sprites/stars/Makefile.am
SUBST_FILES.path+=	graphics/sprites/meteors/Makefile.am
SUBST_FILES.path+=	graphics/sprites/Makefile.am
SUBST_FILES.path+=	graphics/sprites/spaceships/Makefile.am
SUBST_FILES.path+=	graphics/Makefile.am
SUBST_FILES.path+=	src/Makefile.am
SUBST_FILES.path+=	sounds/handheld_console/Makefile.am
SUBST_FILES.path+=	sounds/Makefile.am
SUBST_FILES.path+=	powermanga.6
SUBST_FILES.path+=	src/tools.c

pre-configure:
	cd ${WRKSRC} && autoreconf -fi

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
