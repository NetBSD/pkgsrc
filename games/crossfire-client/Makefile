# $NetBSD: Makefile,v 1.71 2024/10/20 14:03:47 wiz Exp $

DISTNAME=	crossfire-client-1.75.3
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=crossfire/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	https://crossfire.real-time.com/
COMMENT=	Multi-player graphical arcade and adventure game (client)
LICENSE=	gnu-gpl-v2

CONFLICTS+=	crossfire-client-gtk2-[0-9]*
SUPERSEDES+=	crossfire-client-gtk2-[0-9]*
SUPERSEDES+=	crossfire-client-gtk-[0-9]*

USE_CC_FEATURES=	c99
USE_LANGUAGES=		c
USE_TOOLS+=		pkg-config perl:run

REPLACE_PERL+=	common/items.pl

# Gtk2 has to be built with X11: fatal error: 'gdk/gdkx.h' file not found.

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/cmake/build.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
