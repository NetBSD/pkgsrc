# $NetBSD: Makefile,v 1.67 2009/02/26 19:45:14 sno Exp $

DISTNAME=	graphviz-2.20.3
CATEGORIES=	graphics
MASTER_SITES=	http://www.graphviz.org/pub/graphviz/stable/SOURCES/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.graphviz.org/
COMMENT=	Graph Drawing Programs from AT&T Research and Lucent Bell Labs

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+= ghostscript-fonts>=6.0:../../fonts/ghostscript-fonts

CHECK_FILES_SKIP=	${PREFIX}/lib/graphviz/config

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		bison pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-java
CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--disable-php
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-ruby
CONFIGURE_ARGS+=	--disable-sharp
# build fails when PHP and/or Ruby are also installed
CONFIGURE_ENV+=		ac_cv_prog_PHP=
CONFIGURE_ENV+=		ac_cv_prog_RUBY=
CPPFLAGS+=		-DNO_POSTSCRIPT_ALIAS=1
PKGCONFIG_OVERRIDE=		lib/agraph/libagraph.pc.in
PKGCONFIG_OVERRIDE+=	lib/cdt/libcdt.pc.in
PKGCONFIG_OVERRIDE+=	lib/cgraph/libcgraph.pc.in
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

.include "options.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libltdl/convenience.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
#.include "../../graphics/jpeg/buildlink3.mk"
#.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
