# $NetBSD: Makefile,v 1.32 2026/01/02 09:19:51 wiz Exp $

DISTNAME=	KoboDeluxe-0.5.1
PKGREVISION=	8
CATEGORIES=	games
MASTER_SITES=	https://olofson.net/kobodl/download/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	as@rsn.bth.se
HOMEPAGE=	https://olofson.net/kobodl/
COMMENT=	Multi-way scrolling shoot 'em up game for X
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1

GNU_CONFIGURE=		YES
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
BUILD_DEFS+=		VARBASE
CONFIGURE_ARGS+=	--sharedstatedir=${VARBASE}/games

# Fails with C++14 default language.
FORCE_CXX_STD=	c++03

.include "../../mk/bsd.prefs.mk"
.if ${OPSYS} == "Darwin"
MACOS_BUNDLE_PREFIX=	${PREFIX}/Applications
SUBST_CLASSES+=		app
SUBST_STAGE.app=	pre-configure
SUBST_MESSAGE.app=	Fixing installation paths.
SUBST_FILES.app=	Makefile.in data/gfx/Makefile.in data/sfx/Makefile.in
SUBST_VARS.app=		MACOS_BUNDLE_PREFIX
PLIST_SRC=		PLIST.bundle
.endif

.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
