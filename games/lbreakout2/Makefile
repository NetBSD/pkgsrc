# $NetBSD: Makefile,v 1.20 2005/09/23 20:06:25 wiz Exp $

DISTNAME=	lbreakout2-2.5.2
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgames/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://lgames.sourceforge.net/
COMMENT=	Breakout-style arcade game

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--with-highscore-path=${PREFIX}/share/games/ \
			--with-docdir=${PREFIX}/share/doc/html

LDFLAGS.SunOS+=	-lsocket -lnsl

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
