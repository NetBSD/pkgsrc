# $NetBSD: Makefile,v 1.2 2016/07/28 23:42:53 kamil Exp $

DISTNAME=	burgerspace-1.9.2
CATEGORIES=	games
MASTER_SITES=	http://perso.b2b2c.ca/~sarrazip/dev/

MAINTAINER=	pkgsrc-users@NetBSD.rog
HOMEPAGE=	http://perso.b2b2c.ca/~sarrazip/dev/burgerspace.html
COMMENT=	Hamburger-smashing video game
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../devel/flatzebra/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
