# $NetBSD: Makefile,v 1.9 2003/07/13 13:51:53 wiz Exp $
#

DISTNAME=	prboom-2.2.3
PKGREVISION=	4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=prboom/}

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://prboom.sourceforge.net/
COMMENT=	multiplayer-capable and modified version of ID's classic doom game

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

#CONFIGURE_ARGS+=	--enable-gl

.include "../../audio/SDL_mixer/buildlink2.mk"
.include "../../net/SDL_net/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
