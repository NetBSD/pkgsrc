# $NetBSD: Makefile,v 1.107 2010/02/10 19:17:38 joerg Exp $

DISTNAME=		gnome-games-2.28.2
PKGREVISION=		2
CATEGORIES=		games gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-games/2.28/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME2 games collection
#LICENSE=		gnu-gpl-v2 AND gnu-fdl-v1.1

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS=		xbill-[0-9]*
SUPERSEDES=		glchess-[0-9]*

USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_CONFIG_WRAPPER=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR:Q}
CONFIGURE_ENV+=		ac_cv_path_MSGFMT=msgfmt
CONFIGURE_ARGS+=	--localstatedir=${VARBASE:Q}
CONFIGURE_ARGS+=	--without-ggz-server

# Needs devel/check
CONFIGURE_ARGS=		--disable-tests

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
GCONF_SCHEMAS+=	gnome-sudoku.schemas

PYTHON_PATCH_SCRIPTS+=	glchess/src/glchess.in.in
PYTHON_PATCH_SCRIPTS+=	gnome-sudoku/src/gnome-sudoku.in.in
PY_PATCHPLIST=		yes

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/GConf-ui/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.6.3
.include "../../devel/glib2/buildlink3.mk"
#.include "../../devel/libglade/buildlink3.mk"
#BUILDLINK_API_DEPENDS.libgnome+=	libgnome>=2.10.0
#.include "../../devel/libgnome/buildlink3.mk"
#.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../games/ggz-client-libs/buildlink3.mk"
.include "../../games/ggz-client-libs/ggz-client.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
BUILDLINK_API_DEPENDS.librsvg+=	librsvg>=2.12.6
.include "../../graphics/librsvg/buildlink3.mk"
BUILDLINK_API_DEPENDS.clutter+= clutter>=1.0
.include "../../graphics/clutter/buildlink3.mk"
BUILDLINK_API_DEPENDS.clutter-gtk+= clutter-gtk>=0.10
.include "../../graphics/clutter-gtk/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/omf-scrollkeeper.mk"
.include "../../textproc/gnome-doc-utils/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.8.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/py-gnome2-desktop/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
