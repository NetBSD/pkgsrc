# $NetBSD: Makefile,v 1.4 2018/09/25 20:22:34 joerg Exp $

DISTNAME=	quadrupleback-0.1.0
CATEGORIES=	games
MASTER_SITES=	http://perso.b2b2c.ca/~sarrazip/dev/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://perso.b2b2c.ca/~sarrazip/dev/quadrupleback.html
COMMENT=	Game where intruders must be circled
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++03
USE_TOOLS+=	pkg-config

.include "../../devel/SDL_gfx/buildlink3.mk"
.include "../../devel/flatzebra/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
