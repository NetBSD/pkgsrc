# $NetBSD: Makefile,v 1.2 2005/03/27 15:43:36 wiz Exp $

DISTNAME=	lmarbles-1.0.7
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=lgames/}

MAINTAINER=	xs@nitric.net
HOMEPAGE=	http://lgames.sourceforge.net/
COMMENT=	Atomix-like puzzle

USE_BUILDLINK3=		yes
USE_X11=		yes
GNU_CONFIGURE=		yes

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
