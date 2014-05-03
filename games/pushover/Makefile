# $NetBSD: Makefile,v 1.6 2014/05/03 13:14:37 alnsn Exp $
#

DISTNAME=	pushover-0.0.4
PKGREVISION=	5
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=pushover/}

MAINTAINER=	wiz@NetBSD.org
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
