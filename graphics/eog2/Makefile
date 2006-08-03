# $NetBSD: Makefile,v 1.62 2006/08/03 18:53:12 drochner Exp $
#

DISTNAME=	eog-2.14.3
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/eog/2.14/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Eye of GNOME: an image viewing and cataloging program

GNU_CONFIGURE=		YES
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	YES

GCONF2_SCHEMAS= 	eog.schemas

BUILDLINK_API_DEPENDS.libart2+=	libart2>=2.3.16

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/eel2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/popt/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
