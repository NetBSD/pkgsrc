# $NetBSD: Makefile,v 1.56 2022/07/22 17:07:12 micha Exp $

DISTNAME=	crossfire-client-1.73.0
PKGREVISION=	20
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=crossfire/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://crossfire.real-time.com/
COMMENT=	Multi-player graphical arcade and adventure game (client)
LICENSE=	gnu-gpl-v2

CONFLICTS+=	crossfire-client-gtk2-[0-9]*
SUPERSEDES+=	crossfire-client-gtk2-[0-9]*
SUPERSEDES+=	crossfire-client-gtk-[0-9]*

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config perl:run
USE_LANGUAGES=	c99

REPLACE_PERL+=	common/items.pl

.include "../../audio/SDL_mixer/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/SDL_image/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../www/curl/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
