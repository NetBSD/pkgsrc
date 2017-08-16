# $NetBSD: Makefile,v 1.3 2017/08/16 20:45:37 wiz Exp $

DISTNAME=	cosmosmash-1.4.7
CATEGORIES=	games
MASTER_SITES=	http://perso.b2b2c.ca/~sarrazip/dev/

MAINTAINER=	pkgsrc-users@NetBSD.org
#HOMEPAGE=	http://perso.b2b2c.ca/~sarrazip/dev/cosmosmash.html
COMMENT=	Space rock shooting video game
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../devel/flatzebra/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
