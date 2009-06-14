# $NetBSD: Makefile,v 1.15 2009/06/14 19:42:12 wiz Exp $
#

DISTNAME=	gbrainy-1.11
CATEGORIES=	games
MASTER_SITES=	http://www.softcatala.org/~jmas/gbrainy/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://live.gnome.org/gbrainy
COMMENT=	Brain teaser game and trainer
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_DIRS+=	xdg-1.4
USE_LIBTOOL=	yes
USE_LANGUAGES=	c
USE_TOOLS+=	intltool pkg-config bash:run msgfmt

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.2.0

REPLACE_BASH=	src/gbrainy.in

.include "../../devel/mono-addins/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../x11/gnome-sharp/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
