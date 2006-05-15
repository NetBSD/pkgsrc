# $NetBSD: Makefile,v 1.27 2006/05/15 20:21:12 joerg Exp $

DISTNAME=	lbreakout-010315
PKGREVISION=	7
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgames/}

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://lgames.sourceforge.net/
COMMENT=	Breakout-style arcade game

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--disable-sound

USE_LANGUAGES=	c c++

.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
