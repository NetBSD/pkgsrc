# $NetBSD: Makefile,v 1.11 2005/03/27 15:43:36 wiz Exp $
#

DISTNAME=	openmortal-0.7
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openmortal/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://apocalypse.rulez.org/~upi/Mortal/
COMMENT=	Parody of Mortal Kombat with real characters

GNU_CONFIGURE=	yes
USE_BUILDLINK3=	yes
USE_GNU_TOOLS+=	make
USE_PERL5=	yes
USE_X11=	yes

REPLACE_PERL=	data/script/*.pl

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
