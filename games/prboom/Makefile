# $NetBSD: Makefile,v 1.4 2002/08/27 19:08:32 jlam Exp $
#

DISTNAME=	prboom-2.2.2
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
