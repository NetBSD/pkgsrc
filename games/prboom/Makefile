# $NetBSD: Makefile,v 1.1.1.1 2001/07/26 12:33:59 zuntum Exp $
#

DISTNAME=	prboom-2.2.1
CATEGORIES=	games
MASTER_SITES=	http://prdownloads.sourceforge.net/prboom/

MAINTAINER=	zuntum@netbsd.org
HOMEPAGE=	http://prboom.sourceforge.net/
COMMENT=	multiplayer-capable and modified version of ID's classic doom game

USE_BUILDLINK_ONLY=	YES
GNU_CONFIGURE=		YES

#CONFIGURE_ARGS+=	--enable-gl

.include "../../net/SDL_net/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
