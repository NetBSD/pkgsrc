# $NetBSD: Makefile,v 1.14 2005/04/11 21:45:51 tv Exp $

DISTNAME=	ltris-1.0.7
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgames/}

MAINTAINER=	xs@nitric.net
HOMEPAGE=	http://lgames.sourceforge.net/
COMMENT=	SDL tetris clone

USE_X11=		yes
GNU_CONFIGURE=		yes

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
