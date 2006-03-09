# $NetBSD: Makefile,v 1.49 2006/03/09 17:40:24 minskim Exp $

DISTNAME=	graphviz-2.6
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://www.graphviz.org/pub/graphviz/ARCHIVE/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.graphviz.org/
COMMENT=	Graph Drawing Programs from AT&T Research and Lucent Bell Labs

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

.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mgcc-2*)
BUILDLINK_TRANSFORM+=	rm:-Wno-unused-parameter
.endif

CONFIGURE_ENV+=		TCLCONFIG=${TCLCONFIG_SH:Q}
CONFIGURE_ENV+=		TKCONFIG=${TKCONFIG_SH:Q}
CONFIGURE_ENV+=		X11PREFIX=${X11PREFIX:Q} X11BASE=${X11BASE:Q}
# build fails when PHP and/or Ruby are also installed
CONFIGURE_ENV+=		ac_cv_prog_PHP=
CONFIGURE_ENV+=		ac_cv_prog_RUBY=

CPPFLAGS+=	-DNO_POSTSCRIPT_ALIAS=1

# prevent another config.status run
pre-build:
	${TOUCH} ${WRKSRC}/Makefile

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
# The configure script requires gd>=2.0.34, which was never released.
# Uncomment the following when graphics/gd is updated to 2.0.34
#.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
