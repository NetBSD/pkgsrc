# $NetBSD: Makefile,v 1.24 2006/04/17 13:46:29 wiz Exp $

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

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
