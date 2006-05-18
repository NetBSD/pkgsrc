# $NetBSD: Makefile,v 1.25 2006/05/18 11:29:19 rillig Exp $

DISTNAME=	lbreakout2-2.5.2
PKGREVISION=	4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgames/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://lgames.sourceforge.net/
COMMENT=	Breakout-style arcade game

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-highscore-path=${PREFIX}/share/games/ \
			--with-docdir=${PREFIX}/share/doc/html

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Msunpro)
SUBST_CLASSES+=		sunpro
SUBST_STAGE.sunpro=	pre-configure
SUBST_MESSAGE.sunpro=	Removing "inline" for SunPro.
SUBST_FILES.sunpro=	common/tools.h common/tools.c
SUBST_SED.sunpro=	-e 's,^inline ,,'
.endif

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
