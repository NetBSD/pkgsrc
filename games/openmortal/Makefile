# $NetBSD: Makefile,v 1.1.1.1 2003/12/03 18:52:37 xtraeme Exp $
#

DISTNAME=	openmortal-0.3
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=openmortal/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	xtraeme@NetBSD.org
HOMEPAGE=	http://apocalypse.rulez.org/~upi/Mortal/
COMMENT=	Parody of Mortal Kombat with real characters

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_GMAKE=		yes
USE_PERL5=		yes
USE_X11=		yes

REPLACE_PERL=		data/script/*.pl

.include "../../audio/SDL_mixer/buildlink2.mk"
.include "../../devel/SDL/buildlink2.mk"
.include "../../graphics/SDL_image/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../lang/perl5/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
