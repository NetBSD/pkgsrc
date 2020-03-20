# $NetBSD: Makefile,v 1.11 2020/03/20 11:57:43 nia Exp $

DISTNAME=	pushover-0.0.5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pushover/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://pushover.sourceforge.net/
COMMENT=	Remake of Pushover, a fun puzzle game
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL_ttf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
