# $NetBSD: Makefile,v 1.12 2003/11/05 04:32:01 xtraeme Exp $
#

DISTNAME=	prboom-2.2.4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=prboom/}

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://prboom.sourceforge.net/
COMMENT=	Multiplayer-capable and modified version of DOOM

USE_BUILDLINK2=		YES
GNU_CONFIGURE=		YES

#CONFIGURE_ARGS+=	--enable-gl

.include "../../audio/SDL_mixer/buildlink2.mk"
.include "../../net/SDL_net/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
