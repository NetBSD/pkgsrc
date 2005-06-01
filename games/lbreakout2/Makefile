# $NetBSD: Makefile,v 1.18 2005/06/01 18:02:51 jlam Exp $

DISTNAME=	lbreakout2-2.5.2
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgames/}

MAINTAINER=	xs@nitric.net
HOMEPAGE=	http://lgames.sourceforge.net/
COMMENT=	Breakout-style arcade game

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-highscore-path=${LOCALBASE}/share/games/ \
			--with-docdir=${LOCALBASE}/share/doc/html

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
