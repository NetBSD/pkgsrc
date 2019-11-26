# $NetBSD: Makefile,v 1.5 2019/11/26 18:54:05 nia Exp $

DISTNAME=	burgerspace-1.9.3
CATEGORIES=	games
MASTER_SITES=	http://perso.b2b2c.ca/~sarrazip/dev/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://perso.b2b2c.ca/~sarrazip/dev/burgerspace.html
COMMENT=	Hamburger-smashing video game
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../devel/flatzebra/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
