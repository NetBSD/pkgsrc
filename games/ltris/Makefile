# $NetBSD: Makefile,v 1.12 2005/01/12 16:08:46 adam Exp $

DISTNAME=	ltris-1.0.7
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgames/}

MAINTAINER=	xs@nitric.net
HOMEPAGE=	http://lgames.sourceforge.net/
COMMENT=	SDL tetris clone

USE_BUILDLINK3=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
