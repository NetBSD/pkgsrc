# $NetBSD: Makefile,v 1.48 2006/01/20 14:19:48 jmmv Exp $
#

DISTNAME=		gnome-utils-2.12.2
CATEGORIES=		misc gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-utils/2.12/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		rh@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		Set of useful GNOME2 utilities and applications

BUILD_USES_MSGFMT=	yes

USE_TOOLS+=		gmake perl pkg-config
USE_DIRS+=		gnome2-1.5
USE_MSGFMT_PLURALS=	yes
USE_PKGLOCALEDIR=	yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

GCONF2_SCHEMAS+=	gdict.schemas
GCONF2_SCHEMAS+=	gnome-screenshot.schemas
GCONF2_SCHEMAS+=	gnome-search-tool.schemas
GCONF2_SCHEMAS+=	logview.schemas

BUILDLINK_DEPENDS.gnome-vfs2+=	gnome-vfs2>=2.8.4

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/GConf2-ui/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gnome-desktop/buildlink3.mk"
.include "../../x11/gnome-panel/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/curses.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
