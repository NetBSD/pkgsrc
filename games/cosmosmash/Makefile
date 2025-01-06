# $NetBSD: Makefile,v 1.6 2025/01/06 21:49:10 ktnb Exp $

DISTNAME=	cosmosmash-1.4.8
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://perso.b2b2c.ca/~sarrazip/dev/cosmosmash.html
COMMENT=	Space rock shooting video game
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../devel/flatzebra/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
