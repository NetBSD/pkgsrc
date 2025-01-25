# $NetBSD: Makefile,v 1.271 2025/01/25 13:39:36 pin Exp $

DISTNAME=	pango-1.56.1
CATEGORIES=	devel fonts
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/pango/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/GNOME/pango
COMMENT=	Library for layout and rendering of text
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=		c c++
USE_CC_FEATURES+=	c11
USE_TOOLS+=		pkg-config
INSTALLATION_DIRS=	${PKGMANDIR}/man1

SUBST_CLASSES+=		wrksrc
SUBST_STAGE.wrksrc=	pre-configure
SUBST_FILES.wrksrc=	output/utils/pango-view.sh
SUBST_VARS.wrksrc=	WRKSRC

.include "../../mk/bsd.prefs.mk"

MESON_REQD+=		1.2.0
MESON_ARGS+=		-Dcairo=enabled
MESON_ARGS+=		-Dfontconfig=enabled

.if ${USE_CROSS_COMPILE:tl} == "yes"
TOOL_DEPENDS+=			glib2-tools>=0:../../devel/glib2-tools
MESON_BINARIES+=		glib-genmarshal glib-mkenums
MESON_BINARY.glib-genmarshal=	${TOOLBASE}/bin/glib-genmarshal
MESON_BINARY.glib-mkenums=	${TOOLBASE}/bin/glib-mkenums
.endif

PKGCONFIG_OVERRIDE+=		output/meson-private/pango.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/pangocairo.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/pangofc.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/pangoft2.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/pangoot.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/pangoxft.pc
PKGCONFIG_OVERRIDE_STAGE=	pre-install
MAKE_ENV+=			LD_LIBRARY_PATH=${WRKSRC}/output/${PKGBASE}

CHECK_FILES_SKIP+=		${PREFIX}/libdata/pango/pango.modules
CHECK_PORTABILITY_SKIP+=	docs/check.docs

PYTHON_FOR_BUILD_ONLY=	tool

BUILDLINK_TRANSFORM+=	rm:-Werror=implicit-fallthrough # clang10svn

post-extract:
	${MKDIR} -p ${WRKSRC}/output/utils
	${CP} ${FILESDIR}/pango-view.sh ${WRKSRC}/output/utils

post-install:
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/pango-view.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/pango-view.1 || ${TRUE}

.include "options.mk"
.include "../../graphics/librsvg/available.mk"

BUILDLINK_API_DEPENDS.fribidi+=	fribidi>=1.0.6
.include "../../converters/fribidi/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.80
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.fontconfig+=	fontconfig>=2.15.0
.include "../../fonts/fontconfig/buildlink3.mk"
BUILDLINK_API_DEPENDS.harfbuzz+= harfbuzz>=8.4.0
.include "../../fonts/harfbuzz/buildlink3.mk"
.if ${LIBRSVG_TYPE} == "rust"
.include "../../graphics/graphite2/buildlink3.mk"
.endif
BUILDLINK_API_DEPENDS.cairo+=   cairo>=1.18
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
