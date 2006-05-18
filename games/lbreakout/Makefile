# $NetBSD: Makefile,v 1.28 2006/05/18 12:10:12 rillig Exp $

DISTNAME=	lbreakout-010315
PKGREVISION=	8
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgames/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://lgames.sourceforge.net/
COMMENT=	Breakout-style arcade game

GNU_CONFIGURE=		YES
CONFIGURE_ENV+=		VARBASE=${VARBASE:Q}
CONFIGURE_ARGS+=	--disable-sound

USE_LANGUAGES=	c c++

pre-install:
	${INSTALL_DATA_DIR} ${VARBASE:Q}/games

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
