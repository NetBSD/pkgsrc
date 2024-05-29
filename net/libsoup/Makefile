# $NetBSD: Makefile,v 1.78 2024/05/29 16:33:57 adam Exp $

DISTNAME=	libsoup-2.74.3
PKGREVISION=	5
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libsoup/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/libsoup
COMMENT=	HTTP library implementation in C (major version 2)
LICENSE=	gnu-lgpl-v2

DEPENDS+=	glib-networking-[0-9]*:../../net/glib-networking

USE_LANGUAGES=	c99
USE_TOOLS+=	pkg-config msgfmt

PKGCONFIG_OVERRIDE+=		output/meson-private/libsoup-2.4.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/libsoup-gnome-2.4.pc
PKGCONFIG_OVERRIDE_STAGE=	pre-install
MAKE_ENV+=			LD_LIBRARY_PATH=${WRKSRC}/output/${PKGBASE}

# disable vala detection
MESON_ARGS+=		-Dvapi=disabled
# disable sysprof, broken on at least macOS
MESON_ARGS+=		-Dsysprof=disabled

.include "../../mk/compiler.mk"
.if !empty(PKGSRC_COMPILER:Mclang)

_WRAP_EXTRA_ARGS.CC+=	-Wno-error=format-nonliteral
CWRAPPERS_APPEND.cc+=	-Wno-error=format-nonliteral
.endif

PYTHON_FOR_BUILD_ONLY=	tool

.include "options.mk"

.include "../../archivers/brotli/buildlink3.mk"
.include "../../databases/sqlite3/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.58.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=0.9.5
BUILDLINK_DEPMETHOD.gobject-introspection=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../www/libpsl/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
