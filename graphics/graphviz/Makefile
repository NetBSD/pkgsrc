# $NetBSD: Makefile,v 1.41 2005/10/08 11:20:26 adam Exp $

DISTNAME=	graphviz-2.6
CATEGORIES=	graphics
MASTER_SITES=	http://www.graphviz.org/pub/graphviz/ARCHIVE/

MAINTAINER=	seb@NetBSD.org
HOMEPAGE=	http://www.graphviz.org/
COMMENT=	Graph Drawing Programs from AT&T Research and Lucent Bell Labs

BUILDLINK_DEPENDS.gd+=	gd>=2.0.33nb1

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
XAW_TYPE=		standard
PKGCONFIG_OVERRIDE=	lib/agraph/libagraph.pc.in
PKGCONFIG_OVERRIDE+=	lib/cdt/libcdt.pc.in
PKGCONFIG_OVERRIDE+=	lib/graph/libgraph.pc.in
PKGCONFIG_OVERRIDE+=	lib/gvc/libgvc.pc.in
PKGCONFIG_OVERRIDE+=	lib/pathplan/libpathplan.pc.in

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ENV+=		TCLCONFIG=${TCLCONFIG_SH}
CONFIGURE_ENV+=		TKCONFIG=${TKCONFIG_SH}
CONFIGURE_ENV+=		X11PREFIX=${X11PREFIX} X11BASE=${X11BASE}
# build fails when PHP and/or Ruby are also installed
CONFIGURE_ENV+=		ac_cv_prog_PHP=
CONFIGURE_ENV+=		ac_cv_prog_RUBY=

# prevent another config.status run
pre-build:
	${TOUCH} ${WRKSRC}/Makefile

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
