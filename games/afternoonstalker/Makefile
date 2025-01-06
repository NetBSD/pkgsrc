# $NetBSD: Makefile,v 1.4 2025/01/06 21:49:08 ktnb Exp $

DISTNAME=	afternoonstalker-1.1.6
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	https://perso.b2b2c.ca/~sarrazip/dev/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://perso.b2b2c.ca/~sarrazip/dev/afternoonstalker.html
COMMENT=	Robot-killing video game
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../devel/flatzebra/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
