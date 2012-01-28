# $NetBSD: Makefile,v 1.32 2012/01/28 11:00:53 wiz Exp $
#

DISTNAME=	CriticalMass-1.0.2
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=criticalmass/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://criticalmass.sourceforge.net/
COMMENT=	SDL/OpenGL space shoot'em up game

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	YES
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
