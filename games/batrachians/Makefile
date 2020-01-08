# $NetBSD: Makefile,v 1.4 2020/01/08 11:51:41 nia Exp $

DISTNAME=	batrachians-0.1.7
CATEGORIES=	games
MASTER_SITES=	https://perso.b2b2c.ca/~sarrazip/dev/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://perso.b2b2c.ca/~sarrazip/dev/batrachians.html
COMMENT=	Fly-eating frog game
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../devel/flatzebra/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
