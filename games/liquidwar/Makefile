# $NetBSD: Makefile,v 1.11 2012/01/29 21:04:58 marino Exp $
#

DISTNAME=	liquidwar-5.6.4
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.ufoot.org/download/liquidwar/v5/5.6.4/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ufoot.org/liquidwar/v5
COMMENT=	Unique multiplayer wargame

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES

LDFLAGS.DragonFly=	-lm
CONFIGURE_ARGS+=	--disable-doc-ps --disable-doc-pdf
#CONFIGURE_ARGS+=	--enable-debug

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/allegro/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
