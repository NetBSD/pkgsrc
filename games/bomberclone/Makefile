# $NetBSD: Makefile,v 1.1.1.1 2003/06/23 15:48:24 wiz Exp $
#

DISTNAME=		bomberclone-0.9.9
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bomberclone/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@netbsd.org
HOMEPAGE=		http://bomberclone.sourceforge.net/
COMMENT=		multi-player Bomberman clone

DEPENDS+=		bomberclone-data>=0.7:../../games/bomberclone-data

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../audio/SDL_mixer/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
