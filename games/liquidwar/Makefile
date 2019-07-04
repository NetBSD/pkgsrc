# $NetBSD: Makefile,v 1.13 2019/07/04 17:15:21 nia Exp $
#

DISTNAME=	liquidwar-5.6.5
CATEGORIES=	games
MASTER_SITES=	https://www.ufoot.org/download/liquidwar/v5/${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://ufoot.org/liquidwar/v5
COMMENT=	Unique multiplayer wargame
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake
GNU_CONFIGURE=	YES

LDFLAGS.DragonFly=	-lm
CONFIGURE_ARGS+=	--disable-doc-ps --disable-doc-pdf
#CONFIGURE_ARGS+=	--enable-debug

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/allegro/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
