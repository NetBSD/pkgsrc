# $NetBSD: Makefile,v 1.155 2016/03/05 11:28:38 jperkin Exp $

DISTNAME=	graphviz-2.38.0
PKGREVISION=	11
CATEGORIES=	graphics
MASTER_SITES=	http://www.graphviz.org/pub/graphviz/stable/SOURCES/

MAINTAINER=	sno@NetBSD.org
HOMEPAGE=	http://www.graphviz.org/
COMMENT=	Graph Drawing Programs from AT&T Research and Lucent Bell Labs
LICENSE=	epl-v1.0

CHECK_FILES_SKIP+=	${PREFIX}/lib/graphviz/config6

PRIVILEGED_STAGES+=	clean

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		automake bison flex pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-java
CONFIGURE_ARGS+=	--disable-php
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-ruby
CONFIGURE_ARGS+=	--disable-sharp
CONFIGURE_ARGS+=	--disable-r
CONFIGURE_ARGS+=	--with-poppler=no
CONFIGURE_ARGS+=	--with-gts=no
CONFIGURE_ARGS+=	--with-qt=no
# build fails when PHP and/or Ruby are also installed
CONFIGURE_ENV+=		ac_cv_prog_PHP=
CONFIGURE_ENV+=		ac_cv_prog_RUBY=
CPPFLAGS+=		-DNO_POSTSCRIPT_ALIAS=1
PKGCONFIG_OVERRIDE+=	lib/cdt/libcdt.pc.in
PKGCONFIG_OVERRIDE+=	lib/cgraph/libcgraph.pc.in
PKGCONFIG_OVERRIDE+=	lib/expr/libexpr.pc.in
PKGCONFIG_OVERRIDE+=	lib/graph/libgraph.pc.in
PKGCONFIG_OVERRIDE+=	lib/gvc/libgvc.pc.in
PKGCONFIG_OVERRIDE+=	lib/gvpr/libgvpr.pc.in
PKGCONFIG_OVERRIDE+=	lib/pathplan/libpathplan.pc.in
PKGCONFIG_OVERRIDE+=	lib/xdot/libxdot.pc.in
XAW_TYPE=		standard

# With lua51 there's a PLIST divergence and it isn't obvious whether
# it's serious or not, or what causes it.
LUA_VERSIONS_INCOMPATIBLE=	51

REPLACE_LUA+=		tclpkg/gv/demo/modgraph.lua

REPLACE_INTERPRETER+=	tclsh
REPLACE.tclsh.old=	.*tclsh
REPLACE.tclsh.new=	${PREFIX}/bin/tclsh
REPLACE_FILES.tclsh=	tclpkg/gv/demo/modgraph.tcl

REPLACE_PERL+=		config/config_perl.pl \
			tclpkg/gv/demo/modgraph.pl contrib/dotmcl.pl \
			contrib/dirgraph/dirgraph.pl

.include "../../mk/bsd.prefs.mk"

.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mgcc-2*)
BUILDLINK_TRANSFORM+=	rm:-Wno-unused-parameter
.endif

# Prevent another config.status run.
pre-build:
	touch ${WRKSRC}/Makefile ${WRKSRC}/graphviz_version.h

# Remove temporary files and directories created by re-linking "libgv_lua.la".
post-install:
	${RM} -rf ${DESTDIR}${PREFIX}/lib/graphviz/lua/gv.so \
	  ${DESTDIR}${PREFIX}/lib/graphviz/tcl/tcl \
	  ${DESTDIR}${PREFIX}/lib/lua/5.1/gv.so

.include "options.mk"

.include "../../lang/lua/application.mk"

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
#.include "../../devel/libltdl/convenience.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
#.include "../../mk/jpeg.buildlink3.mk"
#.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
