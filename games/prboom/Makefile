# $NetBSD: Makefile,v 1.5 2002/09/06 16:01:38 zuntum Exp $
#

DISTNAME=	prboom-2.2.3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=prboom/}

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://prboom.sourceforge.net/
COMMENT=	multiplayer-capable and modified version of ID's classic doom game

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

#CONFIGURE_ARGS+=	--enable-gl

.include "../../net/SDL_net/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
