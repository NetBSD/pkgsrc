# $NetBSD: Makefile,v 1.5 2020/01/08 11:46:27 nia Exp $

DISTNAME=	quadrupleback-0.1.1
CATEGORIES=	games
MASTER_SITES=	https://perso.b2b2c.ca/~sarrazip/dev/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://perso.b2b2c.ca/~sarrazip/dev/quadrupleback.html
COMMENT=	Game where intruders must be circled
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++03
USE_TOOLS+=	pkg-config

.include "../../devel/SDL_gfx/buildlink3.mk"
.include "../../devel/flatzebra/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
