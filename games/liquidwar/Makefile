# $NetBSD: Makefile,v 1.9 2011/12/12 07:10:24 marino Exp $
#

DISTNAME=	liquidwar-5.6.4
CATEGORIES=	games
MASTER_SITES=	http://www.ufoot.org/download/liquidwar/v5/5.6.4/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ufoot.org/liquidwar/v5
COMMENT=	Unique multiplayer wargame

NOT_FOR_PLATFORM=	DragonFly-*-x86_64     # Can't build 32-bit binaries
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES

CONFIGURE_ARGS+=	--disable-doc-ps --disable-doc-pdf
#CONFIGURE_ARGS+=	--enable-debug

.include "../../devel/allegro/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
