# $NetBSD: Makefile,v 1.23 2006/06/26 21:54:26 wiz Exp $

DISTNAME=		bomberclone-0.11.6.2
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bomberclone/}

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://www.bomberclone.de/
COMMENT=		Multi-player Bomberman clone

CONFLICTS=		bomberclone-data-[0-9]*

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
