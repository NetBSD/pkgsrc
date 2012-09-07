# $NetBSD: Makefile,v 1.54 2012/09/07 19:16:36 adam Exp $
#

DISTNAME=	gbrainy-2.1.4
PKGNAME=	gbrainy-2.14
PKGREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://gent.softcatala.org/jmas/gbrainy/

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

REPLACE_BASH=		src/Clients/Classical/gbrainy.in
# mono-style, pkgsrc infrastructure doesn't change anything in it.
#PKGCONFIG_OVERRIDE=	data/gbrainy.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/mono-addins/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../x11/gtk-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
