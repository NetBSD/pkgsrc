# $NetBSD: Makefile,v 1.13 2003/12/08 14:41:40 wiz Exp $
#

DISTNAME=	prboom-2.2.4
PKGREVISION=	1
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
