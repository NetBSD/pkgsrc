# $NetBSD: Makefile,v 1.18 2005/05/22 20:08:00 jlam Exp $
#

DISTNAME=	CriticalMass-0.9.10
PKGNAME=	${DISTNAME:S/CM/cm/}
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=criticalmass/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://criticalmass.sourceforge.net/
COMMENT=	SDL/OpenGL space shoot'em up game

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake
USE_X11=	YES

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
