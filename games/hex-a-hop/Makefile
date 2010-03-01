# $NetBSD: Makefile,v 1.1.1.1 2010/03/01 11:15:47 wiz Exp $
#

DISTNAME=	hex-a-hop-1.1.0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hexahop/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hexahop.sourceforge.net/
COMMENT=	Hexagonal tile-based puzzle game
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
