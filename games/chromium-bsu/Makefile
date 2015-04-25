# $NetBSD: Makefile,v 1.12 2015/04/25 14:22:53 tnn Exp $

DISTNAME=		chromium-bsu-0.9.15.1
PKGREVISION=		1
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE:=chromium-bsu/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://chromium-bsu.sourceforge.net/
COMMENT=		Fast paced, arcade-style, top-scrolling space shooter

DEPENDS=		uralic-ttf-[0-9]*:../../fonts/uralic-ttf

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
LDFLAGS+=		${BUILDLINK_LDADD.gettext}
LDFLAGS.DragonFly=	-lSDL
LDFLAGS.SunOS=		-lSDL

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/glpng/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/quesoglc/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
