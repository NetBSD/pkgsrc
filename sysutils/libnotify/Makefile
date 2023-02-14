# $NetBSD: Makefile,v 1.73 2023/02/14 13:01:58 wiz Exp $

DISTNAME=	libnotify-0.8.1
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libnotify/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developer.gnome.org/libnotify/
COMMENT=	Desktop notification framework
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	docbook-xsl-[0-9]*:../../textproc/docbook-xsl
TOOL_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt

CONFLICTS+=	libnotify07-[0-9]*
SUPERSEDES+=	libnotify07-[0-9]*

USE_TOOLS+=		pkg-config

PKGCONFIG_OVERRIDE=		output/meson-private/libnotify.pc
PKGCONFIG_OVERRIDE_STAGE=	pre-install
# for testing
#MAKE_ENV+=			LD_LIBRARY_PATH=${WRKSRC}/output/${PKGBASE}

MESON_ARGS+=		-Dintrospection=enabled
# no tests are included
MESON_ARGS+=		-Dtests=false

# Apply removals to post-wrapper transformed arguments.
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,--version-script
BUILDLINK_TRANSFORM.SunOS+=	rm:-Wl,${WRKSRC}/libnotify/libnotify.map

PYTHON_FOR_BUILD_ONLY=	tool

.include "options.mk"

.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.38.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
# gtk3 only needed by tests (which are not included)
#BUILDLINK_DEPMETHOD.gtk3=	build
#.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
