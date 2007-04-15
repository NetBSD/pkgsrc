# $NetBSD: Makefile,v 1.9 2007/04/15 12:58:11 wiz Exp $
#

DISTNAME=		blobwars-1.06-2
PKGNAME=		blobwars-1.06.2
CATEGORIES=		games
MASTER_SITES=		# real site produces wrong filename, use default
# http://www.parallelrealities.co.uk/download.php?type=zip&file=

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.parallelrealities.co.uk/blobWars.php
COMMENT=		Blob Wars: Metal Blob Solid (platform shooter)

USE_LANGUAGES=		c++
WRKSRC=			${WRKDIR}/blobwars-1.06
MAKE_FILE=		makefile
USE_TOOLS+=		gmake
USE_DIRS+=		xdg-1.4

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
