# $NetBSD: Makefile,v 1.11 2005/03/27 15:43:35 wiz Exp $
#

DISTNAME=	gemdropx-0.9
PKGREVISION=	2
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.sonic.net/pub/users/nbs/unix/x/gemdropx/src/

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.newbreedsoftware.com/gemdropx/
COMMENT=	Color puzzle game for X11 similar to Gem Drop

USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make

.include "../../devel/SDL/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
