# $NetBSD: Makefile,v 1.40 2020/03/20 11:57:43 nia Exp $

DISTNAME=	prboom-2.5.0
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=prboom/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://prboom.sourceforge.net/
COMMENT=	Multiplayer-capable and modified version of DOOM

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--with-waddir=${PREFIX}/share/doom

#CONFIGURE_ARGS+=	--enable-gl

SUBST_CLASSES+=		gamesdir
SUBST_STAGE.gamesdir=	pre-configure
SUBST_MESSAGE.gamesdir=	Fixing hard-coded gamesdir
SUBST_FILES.gamesdir=	src/Makefile.in
SUBST_SED.gamesdir+=	-e '/^gamesdir =/ s;/games;/bin;g'

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
