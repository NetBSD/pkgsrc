# $NetBSD: Makefile,v 1.126 2012/09/15 10:04:39 obache Exp $

DISTNAME=		gnome-games-2.32.1
PKGREVISION=		12
CATEGORIES=		games gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-games/2.32/}
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
CONFIGURE_ARGS+=	--enable-omitgames=lightsoff

FILES_SUBST+=		INSTALL=${INSTALL:Q}

GCONF_SCHEMAS=		aisleriot.schemas
GCONF_SCHEMAS+=	glchess.schemas
GCONF_SCHEMAS+=	glines.schemas
GCONF_SCHEMAS+=	gnect.schemas
GCONF_SCHEMAS+=	gnibbles.schemas
GCONF_SCHEMAS+=	gnobots2.schemas
GCONF_SCHEMAS+=	quadrapassel.schemas
GCONF_SCHEMAS+=	gnomine.schemas
GCONF_SCHEMAS+=	gnotravex.schemas
GCONF_SCHEMAS+=	gnotski.schemas
GCONF_SCHEMAS+=	gtali.schemas
GCONF_SCHEMAS+=	iagno.schemas
GCONF_SCHEMAS+=	mahjongg.schemas
GCONF_SCHEMAS+=	swell-foop.schemas
GCONF_SCHEMAS+=	gnome-sudoku.schemas

PYTHON_PATCH_SCRIPTS+=	glchess/src/glchess.in.in
PYTHON_PATCH_SCRIPTS+=	gnome-sudoku/src/gnome-sudoku.in.in
PY_PATCHPLIST=		yes

#!/usr/bin/env sh is pretty dumb and REPLACE_SH doesn't support fixing it
SUBST_CLASSES+=		swell
SUBST_STAGE.swell=	post-patch
SUBST_FILES.swell=	swell-foop/swell-foop.in
SUBST_SED.swell=	's:/usr/bin/env sh:${SH}:'

.include "../../audio/libcanberra/buildlink3.mk"
.include "../../devel/GConf/schemas.mk"
.include "../../devel/GConf-ui/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.6.3
.include "../../devel/glib2/buildlink3.mk"
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
