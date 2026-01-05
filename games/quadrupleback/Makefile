# $NetBSD: Makefile,v 1.7 2026/01/05 21:36:03 ktnb Exp $

DISTNAME=	quadrupleback-0.2.0
CATEGORIES=	games
MASTER_SITES=	http://gvlsywt.cluster051.hosting.ovh.net/dev/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gvlsywt.cluster051.hosting.ovh.net/dev/quadrupleback.html
COMMENT=	Game where intruders must be circled
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++03
USE_TOOLS+=	pkg-config

.include "../../graphics/SDL2_gfx/buildlink3.mk"
.include "../../devel/flatzebra/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
