# $NetBSD$

DISTNAME=	xwpe-1.6.6
CATEGORIES=	editors
MASTER_SITES=	https://codeberg.org/mendezr/xwpe/releases/download/v1.6.6/

MAINTAINER=	vins@NetBSD.org
HOMEPAGE=	https://codeberg.org/mendezr/xwpe/
COMMENT=	Programming environment for UNIX systems
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	gmake pkg-config makeinfo
USE_LANGUAGES=	c
USE_NCURSES=	yes
GNU_CONFIGURE=	yes
INFO_FILES=	yes
ICON_THEMES=	yes

CONFIGURE_ARGS+=	--without-gpm

.include "../../textproc/json-c/buildlink3.mk"
.include "../../devel/libvterm01/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libXft/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
