# $NetBSD: Makefile,v 1.60 2007/09/25 13:59:21 wiz Exp $

DISTNAME=	graphviz-2.12
PKGREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	http://www.graphviz.org/pub/graphviz/ARCHIVE/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.graphviz.org/
COMMENT=	Graph Drawing Programs from AT&T Research and Lucent Bell Labs

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+= ghostscript-fonts>=6.0:../../fonts/ghostscript-fonts

CHECK_FILES_SKIP=	${PREFIX}/lib/graphviz/config

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-gtk
CONFIGURE_ARGS+=	--disable-sharp --disable-python --disable-perl --disable-ruby
CONFIGURE_ENV+=		TCLCONFIG=${TCLCONFIG_SH:Q}
CONFIGURE_ENV+=		TKCONFIG=${TKCONFIG_SH:Q}
CONFIGURE_ENV+=		X11PREFIX=${X11PREFIX:Q} X11BASE=${X11BASE:Q}
# build fails when PHP and/or Ruby are also installed
CONFIGURE_ENV+=		ac_cv_prog_PHP=
CONFIGURE_ENV+=		ac_cv_prog_RUBY=
CPPFLAGS+=		-DNO_POSTSCRIPT_ALIAS=1
PKGCONFIG_OVERRIDE=	lib/agraph/libagraph.pc.in
PKGCONFIG_OVERRIDE+=	lib/cdt/libcdt.pc.in
PKGCONFIG_OVERRIDE+=	lib/expr/libexpr.pc.in
PKGCONFIG_OVERRIDE+=	lib/graph/libgraph.pc.in
PKGCONFIG_OVERRIDE+=	lib/gvc/libgvc.pc.in
PKGCONFIG_OVERRIDE+=	lib/gvc/libgvc_builtins.pc.in
PKGCONFIG_OVERRIDE+=	lib/pathplan/libpathplan.pc.in
XAW_TYPE=		standard

.include "../../mk/bsd.prefs.mk"

.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mgcc-2*)
BUILDLINK_TRANSFORM+=	rm:-Wno-unused-parameter
.endif

# prevent another config.status run
pre-build:
	touch ${WRKSRC}/Makefile

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libltdl/convenience.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/swig/buildlink3.mk"
.include "../../lang/lua/buildlink3.mk"
.include "../../graphics/gd/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/tk/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
