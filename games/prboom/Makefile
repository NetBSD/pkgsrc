# $NetBSD: Makefile,v 1.3 2002/07/20 12:56:45 zuntum Exp $
#

DISTNAME=	prboom-2.2.2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=prboom/}

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://prboom.sourceforge.net/
COMMENT=	multiplayer-capable and modified version of ID's classic doom game

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

#CONFIGURE_ARGS+=	--enable-gl

.include "../../net/SDL_net/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
