# $NetBSD: Makefile,v 1.10 2026/09/02 19:02:05 wiz Exp $

DISTNAME=	batrachians-0.2.0
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://gvlsywt.cluster051.hosting.ovh.net/dev/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gvlsywt.cluster051.hosting.ovh.net/dev/batrachians.html
COMMENT=	Fly-eating frog game
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config

.include "../../devel/flatzebra/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
