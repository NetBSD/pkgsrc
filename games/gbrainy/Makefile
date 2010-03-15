# $NetBSD: Makefile,v 1.23 2010/03/15 11:19:22 wiz Exp $
#

DISTNAME=	gbrainy-1.40
CATEGORIES=	games
MASTER_SITES=	http://www.softcatala.org/~jmas/gbrainy/

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	http://live.gnome.org/gbrainy
COMMENT=	Brain teaser game and trainer
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

MAKE_JOBS_SAFE=	no

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c
USE_TOOLS+=	gmake intltool pkg-config bash:run msgfmt

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.2.0

REPLACE_BASH=		src/gbrainy.in
PKGCONFIG_OVERRIDE=	data/gbrainy.pc.in

.include "../../devel/mono-addins/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../x11/gnome-sharp/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
