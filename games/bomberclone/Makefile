# $NetBSD: Makefile,v 1.8 2003/12/08 14:41:39 wiz Exp $
#

DISTNAME=		bomberclone-0.10.1
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=bomberclone/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		wiz@NetBSD.org
HOMEPAGE=		http://bomberclone.sourceforge.net/
COMMENT=		Multi-player Bomberman clone

CONFLICTS=		bomberclone-data-[0-9]*

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

.include "../../audio/SDL_mixer/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
