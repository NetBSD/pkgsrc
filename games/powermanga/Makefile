# $NetBSD: Makefile,v 1.24 2012/05/16 15:02:41 marino Exp $
#

DISTNAME=	powermanga-0.90
CATEGORIES=	games
MASTER_SITES=	http://linux.tlk.fr/games/Powermanga/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://linux.tlk.fr/games/Powermanga/
COMMENT=	Arcade 2D shoot-em-up game
LICENSE=	gnu-gpl-v3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
MAKE_ENV+=		TOUCH=${TOUCH:Q} WRKSRC=${WRKSRC:Q}
LDFLAGS.DragonFly=	-lm

.include "../../mk/bsd.prefs.mk"

.if ${X11_TYPE} == "modular"
CONFIGURE_ARGS+=	--x-includes=${PREFIX}/include
CONFIGURE_ARGS+=	--x-libraries=${PREFIX}/lib
.endif

SUBST_CLASSES+=		path
SUBST_STAGE.path=	post-patch
SUBST_SED.path+=	-e "s,/games/powermanga,/powermanga,g"
SUBST_MESSAGE.path=	Fixing support file installation paths.
SUBST_FILES.path+=	data/Makefile.in
SUBST_FILES.path+=	data/curves/Makefile.in
SUBST_FILES.path+=	data/levels/curves_phase/Makefile.in
SUBST_FILES.path+=	data/levels/grids_phase/Makefile.in
SUBST_FILES.path+=	graphics/Makefile.in
SUBST_FILES.path+=	graphics/bitmap/Makefile.in
SUBST_FILES.path+=	graphics/bitmap/fonts/Makefile.in
SUBST_FILES.path+=	graphics/sprites/Makefile.in
SUBST_FILES.path+=	graphics/sprites/guardians/Makefile.in
SUBST_FILES.path+=	graphics/sprites/meteors/Makefile.in
SUBST_FILES.path+=	graphics/sprites/spaceships/Makefile.in
SUBST_FILES.path+=	graphics/sprites/stars/Makefile.in
SUBST_FILES.path+=	powermanga.6
SUBST_FILES.path+=	sounds/Makefile.in
SUBST_FILES.path+=	sounds/handheld_console/Makefile.in
SUBST_FILES.path+=	src/tools.c
SUBST_FILES.path+=	texts/Makefile.in

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../x11/libXxf86dga/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/xf86dgaproto/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
