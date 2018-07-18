# $NetBSD: Makefile,v 1.9 2018/07/18 00:06:17 joerg Exp $
#

DISTNAME=	hex-a-hop-1.1.0
PKGREVISION=	5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=hexahop/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hexahop.sourceforge.net/
COMMENT=	Hexagonal tile-based puzzle game
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++03

LIBS.SunOS+=	-liconv

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
