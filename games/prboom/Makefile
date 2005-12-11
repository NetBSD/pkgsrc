# $NetBSD: Makefile,v 1.21 2005/12/11 09:40:43 wiz Exp $

DISTNAME=	prboom-2.2.6
PKGREVISION=	2
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
