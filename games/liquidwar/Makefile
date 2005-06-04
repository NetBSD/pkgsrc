# $NetBSD: Makefile,v 1.1.1.1 2005/06/04 11:18:12 wiz Exp $
#

DISTNAME=	liquidwar-5.6.2
CATEGORIES=	games
#MASTER_SITES=	http://savannah.nongnu.org/download/liquidwar/
MASTER_SITES=	http://liquidwar.sunsite.dk/archive/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://www.ufoot.org/liquidwar/
COMMENT=	Unique multiplayer wargame

USE_DIRS+=	gnome2-1.5
USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES

#CONFIGURE_ARGS+=	--enable-debug

.include "../../devel/allegro/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
