# $NetBSD: Makefile,v 1.33 2004/04/20 15:48:11 jmmv Exp $

DISTNAME=		gnome-games-2.6.1
CATEGORIES=		games gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-games/2.6/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME2 games collection

DEPENDS+=		librsvg2-gtk2>=2.6.3:../../graphics/librsvg2-gtk2

CONFLICTS=		xbill-[0-9]*

USE_BUILDLINK3=		yes
USE_DIRS+=		gnome2-1.5
USE_PKGLOCALEDIR=	yes
USE_GNU_TOOLS+=		make
USE_X11=		yes
USE_CONFIG_WRAPPER=	yes
USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes

USE_PKGINSTALL=		yes
INSTALL_EXTRA_TMPL+=	${.CURDIR}/INSTALL

GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PKGLOCALEDIR=${PKGLOCALEDIR}
CONFIGURE_ARGS+=	--localstatedir=/var
# This package installs files in sysconfdir but does not read them directly,
# so the following configuration argument is safe.
CONFIGURE_ARGS+=	--sysconfdir=${EGDIR}

EGDIR=			${PREFIX}/share/examples/gnome2-games
CONF_FILES=
.for conffile in	sound/events/gataxx.soundlist \
			sound/events/gnect.soundlist \
			sound/events/gnibbles.soundlist \
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
GCONF2_SCHEMAS+=	gnotravex.schemas
GCONF2_SCHEMAS+=	gtali.schemas
GCONF2_SCHEMAS+=	iagno.schemas
GCONF2_SCHEMAS+=	mahjongg.schemas
GCONF2_SCHEMAS+=	same-gnome.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/GConf2-ui/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkgconfig/buildlink3.mk"
.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../lang/guile/buildlink3.mk"
.include "../../sysutils/gnome-vfs2/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/bsd.pkg.mk"
