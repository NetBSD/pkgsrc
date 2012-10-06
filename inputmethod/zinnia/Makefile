# $NetBSD: Makefile,v 1.2 2012/10/06 14:25:22 asau Exp $
#

.include "Makefile.common"

COMMENT=	Online hand writing recognition system with machine learning

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	zinnia.pc.in

.include "../../mk/bsd.pkg.mk"
