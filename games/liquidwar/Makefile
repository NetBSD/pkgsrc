# $NetBSD: Makefile,v 1.12 2012/10/06 11:54:46 asau Exp $
#

DISTNAME=	liquidwar-5.6.4
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.ufoot.org/download/liquidwar/v5/5.6.4/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ufoot.org/liquidwar/v5
COMMENT=	Unique multiplayer wargame

USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES

LDFLAGS.DragonFly=	-lm
CONFIGURE_ARGS+=	--disable-doc-ps --disable-doc-pdf
#CONFIGURE_ARGS+=	--enable-debug

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/allegro/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
