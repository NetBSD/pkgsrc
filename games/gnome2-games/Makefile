# $NetBSD: Makefile,v 1.12 2003/09/28 09:13:57 jlam Exp $

DISTNAME=		gnome-games-2.2.1
PKGREVISION=		4
CATEGORIES=		games gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-games/2.2/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		tech-pkg@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME2 games collection

BUILD_USES_MSGFMT=	yes
DEPENDS+=		gnome2-dirs>=1.2:../../misc/gnome2-dirs

CONFLICTS=		xbill-[0-9]*

USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_GMAKE=		yes
USE_X11=		yes
USE_CONFIG_WRAPPER=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool

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

post-patch:
	cd ${WRKSRC} &&							\
	${CP} gnect/src/connect4.c gnect/src/connect4.c.broken &&	\
	${SED} -e 's|/usr/share|${PREFIX}/share|'			\
		< gnect/src/connect4.c.broken > gnect/src/connect4.c

GCONF2_SCHEMAS=		freecell.schemas
GCONF2_SCHEMAS+=	gataxx.schemas
GCONF2_SCHEMAS+=	gnect.schemas
GCONF2_SCHEMAS+=	gnometris.schemas
GCONF2_SCHEMAS+=	gnomine.schemas
GCONF2_SCHEMAS+=	gtali.schemas
GCONF2_SCHEMAS+=	iagno.schemas
GCONF2_SCHEMAS+=	mahjongg.schemas
GCONF2_SCHEMAS+=	same-gnome.schemas

.include "../../devel/GConf2/schemas.mk"
.include "../../devel/GConf2-ui/buildlink2.mk"
.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/libgnome/buildlink2.mk"
.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../devel/ncurses/buildlink2.mk"
.include "../../lang/guile/buildlink2.mk"
.include "../../textproc/scrollkeeper/omf.mk"
.include "../../mk/bsd.pkg.mk"
