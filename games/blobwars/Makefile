# $NetBSD: Makefile,v 1.1.1.1 2005/10/03 21:13:18 wiz Exp $
#

DISTNAME=		blobwars-1.04-1
PKGNAME=		blobwars-1.04.1
CATEGORIES=		games
MASTER_SITES=		# real site produces wrong filename, use default
# http://www.parallelrealities.co.uk/download.php?type=zip&file=

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.parallelrealities.co.uk/blobWars.php
COMMENT=		Blob Wars: Metal Blob Solid (platform shooter)

WRKSRC=			${WRKDIR}/blobwars-1.04
MAKEFILE=		makefile
USE_TOOLS+=		gmake

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
