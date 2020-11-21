# $NetBSD: Makefile,v 1.225 2020/11/21 09:34:55 wiz Exp $

DISTNAME=	graphviz-2.44.1
PKGREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	https://www2.graphviz.org/Packages/stable/portable_source/

MAINTAINER=	sno@NetBSD.org
HOMEPAGE=	https://www.graphviz.org/
COMMENT=	Graph Drawing Programs from AT&T Research and Lucent Bell Labs
LICENSE=	epl-v1.0

TOOL_DEPENDS+=	ghostscript-[0-9]*:../../print/ghostscript

CHECK_FILES_SKIP+=		${PREFIX}/lib/graphviz/config6
CHECK_PORTABILITY_SKIP+=	windows/*

USE_LANGUAGES=		c c++
USE_LIBTOOL=		yes
USE_TOOLS+=		automake bison flex groff pkg-config
# GNU make is needed since BSD Make does not know $< in explicit rules,
# such as used by lib/cdt/Makefile.am.
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
GNU_CONFIGURE_STRICT=	no # has sub-configures
CONFIGURE_ARGS+=	--disable-java
CONFIGURE_ARGS+=	--disable-php
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--disable-python2
CONFIGURE_ARGS+=	--disable-python3
CONFIGURE_ARGS+=	--disable-r
CONFIGURE_ARGS+=	--disable-ruby
CONFIGURE_ARGS+=	--disable-sharp
CONFIGURE_ARGS+=	--enable-ltdl
CONFIGURE_ARGS+=	--without-qt
# build fails when PHP and/or Ruby are also installed
CONFIGURE_ENV+=		ac_cv_prog_PHP=
CONFIGURE_ENV+=		ac_cv_prog_RUBY=
CPPFLAGS+=		-DNO_POSTSCRIPT_ALIAS=1

PKGCONFIG_OVERRIDE+=	lib/cdt/libcdt.pc.in
PKGCONFIG_OVERRIDE+=	lib/cgraph/libcgraph.pc.in
PKGCONFIG_OVERRIDE+=	lib/edgepaint/liblab_gamut.pc.in
PKGCONFIG_OVERRIDE+=	lib/expr/libexpr.pc.in
PKGCONFIG_OVERRIDE+=	lib/gvc/libgvc.pc.in
PKGCONFIG_OVERRIDE+=	lib/gvpr/libgvpr.pc.in
PKGCONFIG_OVERRIDE+=	lib/pathplan/libpathplan.pc.in
PKGCONFIG_OVERRIDE+=	lib/sfdpgen/libsfdp.pc.in
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

REPLACE_PERL+=		tclpkg/gv/demo/modgraph.pl contrib/dotmcl.pl \
			contrib/dirgraph/dirgraph.pl

.include "../../mk/bsd.prefs.mk"

.include "../../mk/compiler.mk"
.if !empty(CC_VERSION:Mgcc-2*)
BUILDLINK_TRANSFORM+=	rm:-Wno-unused-parameter
.endif

.if ${OPSYS} == "FreeBSD"
SUBST_CLASSES+=		sfflags
SUBST_STAGE.sfflags=	pre-configure
SUBST_MESSAGE.sfflags=	Fixing SF_FLAGS identifier for FreeBSD.
SUBST_FILES.sfflags=	lib/sfio/sfclrlock.c lib/sfio/sfio_t.h lib/sfio/sfio.h
SUBST_FILES.sfflags+=	lib/sfio/sfnew.c lib/sfio/sfopen.c lib/sfio/sfset.c
SUBST_SED.sfflags=	-e 's|SF_FLAGS|SFIO_FLAGS|g'
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
.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/gts/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
