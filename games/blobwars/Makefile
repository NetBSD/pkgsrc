# $NetBSD: Makefile,v 1.6 2006/05/22 17:26:38 wiz Exp $
#

DISTNAME=		blobwars-1.04-1
PKGNAME=		blobwars-1.04.1
PKGREVISION=		3
CATEGORIES=		games
MASTER_SITES=		# real site produces wrong filename, use default
# http://www.parallelrealities.co.uk/download.php?type=zip&file=

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.parallelrealities.co.uk/blobWars.php
COMMENT=		Blob Wars: Metal Blob Solid (platform shooter)

USE_LANGUAGES=		c++
WRKSRC=			${WRKDIR}/blobwars-1.04
MAKEFILE=		makefile
USE_TOOLS+=		gmake

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
