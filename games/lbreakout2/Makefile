# $NetBSD: Makefile,v 1.22 2006/02/05 23:09:19 joerg Exp $

DISTNAME=	lbreakout2-2.5.2
PKGREVISION=	3
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
