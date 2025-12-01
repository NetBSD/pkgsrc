# $NetBSD: Makefile,v 1.7 2025/12/01 09:14:36 wiz Exp $

DISTNAME=	cosmosmash-1.4.8
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	#

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gvlsywt.cluster051.hosting.ovh.net/dev/cosmosmash.html
COMMENT=	Space rock shooting video game
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../devel/flatzebra/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
