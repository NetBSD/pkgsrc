# $NetBSD: Makefile,v 1.90 2009/03/18 01:03:36 jmcneill Exp $

DISTNAME=		gnome-games-2.26.0
CATEGORIES=		games gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-games/2.26/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME2 games collection

PKG_DESTDIR_SUPPORT=	user-destdir

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
CONFIGURE_ARGS+=	--without-ggz-server

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

PYTHON_PATCH_SCRIPTS+=	glchess/src/glchess.in.in
PYTHON_PATCH_SCRIPTS+=	gnome-sudoku/src/gnome-sudoku.in.in
PY_PATCHPLIST=		yes

# The gettext version in pkgsrc cannot handle the .po files, so
# we strip out usage of the newer features (context and fuzzy matches)
post-patch:
	for f in \
	    ${WRKSRC}/aisleriot/help/*/*.po \
	    ${WRKSRC}/blackjack/help/*/*.po \
	    ${WRKSRC}/glchess/help/*/*.po \
	    ${WRKSRC}/glines/help/*/*.po \
	    ${WRKSRC}/gnect/help/*/*.po \
	    ${WRKSRC}/gnibbles/help/*/*.po \
	    ${WRKSRC}/gnome-sudoku/help/*/*.po \
	    ${WRKSRC}/gnometris/help/*/*.po \
	    ${WRKSRC}/gnomine/help/*/*.po \
	    ${WRKSRC}/gnobots2/help/*/*.po \
	    ${WRKSRC}/gnotravex/help/*/*.po \
	    ${WRKSRC}/gnotski/help/*/*.po \
	    ${WRKSRC}/gtali/help/*/*.po \
	    ${WRKSRC}/iagno/help/*/*.po \
	    ${WRKSRC}/mahjongg/help/*/*.po \
	    ${WRKSRC}/same-gnome/help/*/*.po \
	    ${WRKSRC}/po/*.po \
	    ; do \
		mv $$f $$f.original ; \
		${AWK} -f ${FILESDIR}/msgfmtstrip $$f.original > $$f ; \
	done

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.6.3
BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.8.0
BUILDLINK_API_DEPENDS.libgnome+=	libgnome>=2.10.0
BUILDLINK_API_DEPENDS.librsvg+=	librsvg>=2.12.6

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
