# $NetBSD: Makefile,v 1.116 2023/11/14 14:01:52 wiz Exp $

DISTNAME=	gbrainy-2.4.1
PKGNAME=	gbrainy-2.41
PKGREVISION=	17
CATEGORIES=	games
MASTER_SITES=	https://gent.softcatala.org/jmas/gbrainy/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Apps/gbrainy
COMMENT=	Brain teaser game and trainer
LICENSE=	gnu-gpl-v2

MAKE_JOBS_SAFE=	no

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_LANGUAGES=	c
USE_TOOLS+=	gmake intltool pkg-config bash:run
USE_TOOLS+=	msgfmt msgmerge xgettext itstool

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.2.0

REPLACE_BASH=		src/Clients/Classical/gbrainy.in
# mono-style, pkgsrc infrastructure doesn't change anything in it.
#PKGCONFIG_OVERRIDE=	data/gbrainy.pc.in

.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/mono/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk-sharp3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
