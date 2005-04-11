# $NetBSD: Makefile,v 1.20 2005/04/11 21:45:56 tv Exp $

DISTNAME=	prboom-2.2.6
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=prboom/}

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://prboom.sourceforge.net/
COMMENT=	Multiplayer-capable and modified version of DOOM

GNU_CONFIGURE=		YES

#CONFIGURE_ARGS+=	--enable-gl

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
