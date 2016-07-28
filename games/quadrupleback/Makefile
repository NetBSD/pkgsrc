# $NetBSD: Makefile,v 1.1 2016/07/28 22:31:54 kamil Exp $

DISTNAME=	quadrupleback-0.1.0
CATEGORIES=	games
MASTER_SITES=	http://perso.b2b2c.ca/~sarrazip/dev/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://perso.b2b2c.ca/~sarrazip/dev/afternoonstalker.html
COMMENT=	Game where intruders must be circled
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../devel/SDL_gfx/buildlink3.mk"
.include "../../devel/flatzebra/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
