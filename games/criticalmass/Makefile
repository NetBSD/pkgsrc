# $NetBSD: Makefile,v 1.10 2004/01/24 13:30:55 grant Exp $
#

DISTNAME=	CriticalMass-0.98
PKGNAME=	${DISTNAME:S/CM/cm/}
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=criticalmass/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://criticalmass.sourceforge.net/
COMMENT=	SDL/OpenGL space shoot'em up game

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_GNU_TOOLS+=	make
USE_X11=	YES

.include "../../devel/SDL/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/SDL_image/buildlink2.mk"
.include "../../audio/SDL_mixer/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
