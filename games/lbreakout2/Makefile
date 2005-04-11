# $NetBSD: Makefile,v 1.17 2005/04/11 21:45:51 tv Exp $

DISTNAME=	lbreakout2-2.5.2
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgames/}

MAINTAINER=	xs@nitric.net
HOMEPAGE=	http://lgames.sourceforge.net/
COMMENT=	Breakout-style arcade game

USE_X11=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-highscore-path=${LOCALBASE}/share/games/ \
			--with-docdir=${LOCALBASE}/share/doc/html

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
