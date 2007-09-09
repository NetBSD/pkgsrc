# $NetBSD: Makefile,v 1.4 2007/09/09 16:59:19 wiz Exp $
#

DISTNAME=	liquidwar-5.6.3
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://ufoot.hd.free.fr/pub/archive/ \
		http://www.ufoot.org/archive/ \
		http://download.savannah.nongnu.org/releases/liquidwar/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ufoot.org/liquidwar/
COMMENT=	Unique multiplayer wargame

USE_DIRS+=	gnome2-1.5
USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES

#CONFIGURE_ARGS+=	--enable-debug

.include "../../devel/allegro/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
