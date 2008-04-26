# $NetBSD: Makefile,v 1.82 2008/04/26 00:07:27 wiz Exp $

DISTNAME=		gnome-games-2.22.1.1
CATEGORIES=		games gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-games/2.22/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME2 games collection

CONFLICTS=		xbill-[0-9]*

USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_CONFIG_WRAPPER=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR:Q}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}

FILES_SUBST+=		INSTALL=${INSTALL:Q}

GCONF_SCHEMAS=		aisleriot.schemas
GCONF_SCHEMAS+=	blackjack.schemas
GCONF_SCHEMAS+=	glchess.schemas
GCONF_SCHEMAS+=	glines.schemas
GCONF_SCHEMAS+=	gnect.schemas
GCONF_SCHEMAS+=	gnibbles.schemas
GCONF_SCHEMAS+=	gnobots2.schemas
GCONF_SCHEMAS+=	gnometris.schemas
GCONF_SCHEMAS+=	gnomine.schemas
GCONF_SCHEMAS+=	gnotravex.schemas
GCONF_SCHEMAS+=	gnotski.schemas
GCONF_SCHEMAS+=	gtali.schemas
GCONF_SCHEMAS+=	iagno.schemas
GCONF_SCHEMAS+=	mahjongg.schemas
GCONF_SCHEMAS+=	same-gnome.schemas

PYTHON_PATCH_SCRIPTS+=	glchess/src/glchess
PYTHON_PATCH_SCRIPTS+=	gnome-sudoku/src/gnome-sudoku
PY_PATCHPLIST=		yes

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.6.3
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.8.0
BUILDLINK_API_DEPENDS.libgnome+=	libgnome>=2.10.0
BUILDLINK_API_DEPENDS.librsvg+=	librsvg>=2.12.6

.include "../../audio/esound/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/GConf-ui/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../games/ggz-client-libs/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-gnome2-desktop/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
