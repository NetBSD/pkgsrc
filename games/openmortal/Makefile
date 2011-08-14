# $NetBSD: Makefile,v 1.33 2011/08/14 12:45:37 obache Exp $
#

DISTNAME=	openmortal-0.7
PKGREVISION=	15
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openmortal/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://apocalypse.rulez.org/~upi/Mortal/
COMMENT=	Parody of Mortal Kombat with real characters

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake

REPLACE_PERL=	data/script/*.pl

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../lang/perl5/buildlink3.mk"
.include "../../net/SDL_net/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
