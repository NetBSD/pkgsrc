# $NetBSD: Makefile,v 1.5 2007/11/29 17:28:24 wiz Exp $
#

DISTNAME=	liquidwar-5.6.4
CATEGORIES=	games
MASTER_SITES=	http://www.ufoot.org/download/liquidwar/v5/5.6.4/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ufoot.org/liquidwar/v5
COMMENT=	Unique multiplayer wargame

USE_DIRS+=	gnome2-1.5
USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES

#CONFIGURE_ARGS+=	--enable-debug

.include "../../devel/allegro/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
