# $NetBSD: Makefile,v 1.4 2003/12/08 14:41:39 wiz Exp $

DISTNAME=	defendguin-0.0.10
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.nbswebfx.com/downloads/

MAINTAINER=	reed@reedmedia.net
HOMEPAGE=	http://www.newbreedsoftware.com/defendguin/
COMMENT=	Clone of the arcade game Defender

USE_X11=	YES
USE_BUILDLINK2=	YES

USE_GMAKE=	YES
MAKE_ENV+=	PREFIX=${LOCALBASE}

.include "../../audio/SDL_mixer/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
