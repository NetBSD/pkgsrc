# $NetBSD: Makefile,v 1.11 2004/06/23 15:48:41 snj Exp $

DISTNAME=		bomberclone-0.11.3
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bomberclone/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.bomberclone.de/
COMMENT=		Multi-player Bomberman clone

CONFLICTS=		bomberclone-data-[0-9]*

GNU_CONFIGURE=		yes
USE_BUILDLINK3=		yes
USE_PKGLOCALEDIR=	yes

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
