# $NetBSD: Makefile,v 1.7 2009/06/09 03:04:00 dsainty Exp $
#

DISTNAME=	liquidwar-5.6.4
CATEGORIES=	games
MASTER_SITES=	http://www.ufoot.org/download/liquidwar/v5/5.6.4/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ufoot.org/liquidwar/v5
COMMENT=	Unique multiplayer wargame

PKG_DESTDIR_SUPPORT=	user-destdir

USE_DIRS+=	gnome2-1.5
USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--disable-doc-ps --disable-doc-pdf
#CONFIGURE_ARGS+=	--enable-debug

.include "../../devel/allegro/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
