# $NetBSD: Makefile,v 1.74 2006/09/15 15:22:39 jmmv Exp $

DISTNAME=		gnome-games-2.15.92
CATEGORIES=		games gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-games/2.15/}
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
# This package installs files in sysconfdir but does not read them directly,
# so the following configuration argument is safe.
CONFIGURE_ARGS+=	--sysconfdir=${EGDIR:Q}

EGDIR=			${PREFIX}/share/examples/gnome2-games
CONF_FILES=
.for conffile in	sound/events/gnibbles.soundlist \
			sound/events/gnobots2.soundlist \
			sound/events/iagno.soundlist
CONF_FILES+=		${EGDIR}/${conffile} ${PKG_SYSCONFDIR}/${conffile}
.endfor

FILES_SUBST+=		INSTALL=${INSTALL:Q}

GCONF2_SCHEMAS=		aisleriot.schemas
GCONF2_SCHEMAS+=	blackjack.schemas
GCONF2_SCHEMAS+=	gataxx.schemas
GCONF2_SCHEMAS+=	glines.schemas
GCONF2_SCHEMAS+=	gnect.schemas
GCONF2_SCHEMAS+=	gnibbles.schemas
GCONF2_SCHEMAS+=	gnobots2.schemas
GCONF2_SCHEMAS+=	gnometris.schemas
GCONF2_SCHEMAS+=	gnomine.schemas
GCONF2_SCHEMAS+=	gnotski.schemas
GCONF2_SCHEMAS+=	gnotravex.schemas
GCONF2_SCHEMAS+=	gtali.schemas
GCONF2_SCHEMAS+=	iagno.schemas
GCONF2_SCHEMAS+=	libgnomegames.schemas
GCONF2_SCHEMAS+=	mahjongg.schemas
GCONF2_SCHEMAS+=	same-gnome.schemas

PYTHON_PATCH_SCRIPTS=	libgames-support/games-server.py

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.6.3
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.8.0
BUILDLINK_API_DEPENDS.howl+=	howl>=0.9.6
BUILDLINK_API_DEPENDS.libgnome+=	libgnome>=2.10.0
BUILDLINK_API_DEPENDS.librsvg2+=	librsvg2>=2.12.6

.include "../../audio/esound/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/GConf2-ui/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../net/howl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
