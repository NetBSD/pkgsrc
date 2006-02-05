# $NetBSD: Makefile,v 1.3 2006/02/05 23:09:20 joerg Exp $
#

DISTNAME=	liquidwar-5.6.3
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://ufoot.hd.free.fr/pub/archive/ \
		http://www.ufoot.org/archive/ \
		http://download.savannah.nongnu.org/releases/liquidwar/

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
