# $NetBSD: Makefile,v 1.2 2003/04/27 20:29:18 cjep Exp $
#

DISTNAME=	CriticalMass-0.97
PKGNAME=	criticalmass-0.97
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=criticalmass/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jrp@hispabsd.org
HOMEPAGE=	http://criticalmass.sourceforge.net/
COMMENT=	SDL/OpenGL space shoot'em up game

USE_BUILDLINK2=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
USE_X11=	YES

.include "../../devel/SDL/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/SDL_image/buildlink2.mk"
.include "../../audio/SDL_mixer/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
