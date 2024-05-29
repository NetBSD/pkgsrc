# $NetBSD: Makefile,v 1.21 2024/05/29 16:32:41 adam Exp $
#

DISTNAME=	lincity-ng-2.0
PKGREVISION=	17
CATEGORIES=	games
MASTER_SITES=	http://download.berlios.de/lincity-ng/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
#HOMEPAGE=	http://lincity-ng.berlios.de/wiki/index.php/Main_Page
COMMENT=	Open source SimCity like game
LICENSE=	gnu-gpl-v2 #AND cc-by-sa-v2.0 AND Bitstream Vera Fonts

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

TOOL_DEPENDS+=	jam-[0-9]*:../../devel/jam

USE_TOOLS+=	pkg-config

do-build:
	cd ${WRKSRC} && env ${MAKE_ENV} jam

do-install:
	cd ${WRKSRC} && env ${MAKE_ENV} jam prefix=${DESTDIR}${PREFIX} install

.include "../../devel/SDL/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../devel/SDL_gfx/buildlink3.mk"
.include "../../devel/physfs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
