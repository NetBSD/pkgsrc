# $NetBSD: Makefile,v 1.20 2005/12/11 09:40:40 wiz Exp $
#

DISTNAME=	CriticalMass-0.9.10
PKGNAME=	${DISTNAME:S/CM/cm/}
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=criticalmass/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://criticalmass.sourceforge.net/
COMMENT=	SDL/OpenGL space shoot'em up game

GNU_CONFIGURE=	YES
USE_TOOLS+=	gmake

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
