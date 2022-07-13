# $NetBSD: Makefile,v 1.251 2022/07/13 20:32:01 adam Exp $

DISTNAME=	pango-1.50.8
CATEGORIES=	devel fonts
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/pango/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://pango.gnome.org/
COMMENT=	Library for layout and rendering of text
LICENSE=	gnu-lgpl-v2

TOOL_DEPENDS+=		help2man-[0-9]*:../../converters/help2man

USE_LANGUAGES=		c c++
USE_TOOLS+=		pkg-config
INSTALLATION_DIRS=	${PKGMANDIR}/man1

SUBST_CLASSES+=		wrksrc
SUBST_STAGE.wrksrc=	pre-configure
SUBST_FILES.wrksrc=	output/utils/pango-view.sh
SUBST_VARS.wrksrc=	WRKSRC

MESON_REQD+=		0.55.3
MESON_ARGS+=		-Dcairo=enabled
MESON_ARGS+=		-Dfontconfig=enabled
MESON_ARGS+=		-Dintrospection=enabled

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
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.60
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
BUILDLINK_API_DEPENDS.fontconfig+=	fontconfig>=2.11.91
.include "../../fonts/fontconfig/buildlink3.mk"
BUILDLINK_API_DEPENDS.harfbuzz+= harfbuzz>=2.7.2
.include "../../fonts/harfbuzz/buildlink3.mk"
.if ${LIBRSVG_TYPE} == "rust"
.include "../../graphics/graphite2/buildlink3.mk"
.endif
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.12.10
.include "../../graphics/cairo/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
# XXX freetype versioning is insane. needs libtool version >= 21.0.15,
# which corresponds to release version 2.8.1
BUILDLINK_API_DEPENDS.freetype2+= freetype2>=2.8.1
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
