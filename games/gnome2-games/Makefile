# $NetBSD: Makefile,v 1.51 2005/10/10 14:03:36 jmmv Exp $

DISTNAME=		gnome-games-2.10.1
PKGREVISION=		1
CATEGORIES=		games gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-games/2.10/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME2 games collection

CONFLICTS=		xbill-[0-9]*

BUILD_USES_MSGFMT=	yes

USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
USE_CONFIG_WRAPPER=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_MSGFMT_PLURALS=	yes

USE_PKGINSTALL=		yes
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR}
CONFIGURE_ARGS+=	--localstatedir=${VARBASE}
# This package installs files in sysconfdir but does not read them directly,
# so the following configuration argument is safe.
CONFIGURE_ARGS+=	--sysconfdir=${EGDIR}

EGDIR=			${PREFIX}/share/examples/gnome2-games
CONF_FILES=
.for conffile in	sound/events/gnibbles.soundlist \
			sound/events/gnobots2.soundlist \
			sound/events/iagno.soundlist
CONF_FILES+=		${EGDIR}/${conffile} ${PKG_SYSCONFDIR}/${conffile}
.endfor
.undef conffile

FILES_SUBST+=		INSTALL="${INSTALL}"

GCONF2_SCHEMAS=		aisleriot.schemas
GCONF2_SCHEMAS+=	blackjack.schemas
GCONF2_SCHEMAS+=	gataxx.schemas
GCONF2_SCHEMAS+=	glines.schemas
GCONF2_SCHEMAS+=	gnect.schemas
GCONF2_SCHEMAS+=	gnibbles.schemas
GCONF2_SCHEMAS+=	gnobots2.schemas
GCONF2_SCHEMAS+=	gnome-stones.schemas
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

BUILDLINK_DEPENDS.howl+=	howl>=0.9.6
BUILDLINK_DEPENDS.libgnome+=	libgnome>=2.10.0
BUILDLINK_DEPENDS.librsvg2+=	librsvg2>=2.12.6

.include "../../audio/esound/buildlink3.mk"
.include "../../devel/GConf2/schemas.mk"
.include "../../devel/GConf2-ui/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../net/howl/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
