# $NetBSD: Makefile,v 1.16 2004/09/25 20:02:54 snj Exp $

DISTNAME=	prboom-2.2.5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=prboom/}

MAINTAINER=	snj@NetBSD.org
HOMEPAGE=	http://prboom.sourceforge.net/
COMMENT=	Multiplayer-capable and modified version of DOOM

USE_BUILDLINK3=		YES
GNU_CONFIGURE=		YES

#CONFIGURE_ARGS+=	--enable-gl

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
