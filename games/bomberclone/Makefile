# $NetBSD: Makefile,v 1.5 2003/07/26 21:41:15 jmmv Exp $
#

DISTNAME=		bomberclone-0.9.9
PKGREVISION=		2
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bomberclone/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://bomberclone.sourceforge.net/
COMMENT=		Multi-player Bomberman clone

DEPENDS+=		bomberclone-data>=0.7:../../games/bomberclone-data

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../audio/SDL_mixer/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
