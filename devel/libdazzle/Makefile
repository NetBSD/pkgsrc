# $NetBSD: Makefile,v 1.19 2022/08/11 05:08:11 gutteridge Exp $

DISTNAME=	libdazzle-3.38.0
PKGREVISION=	6
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libdazzle/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/GNOME/libdazzle
COMMENT=	Companion library to GObject and Gtk+
LICENSE=	gnu-gpl-v3

USE_TOOLS+=	pkg-config

# workaround for build failure
# https://gitlab.gnome.org/GNOME/json-glib/issues/35
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/src

PYTHON_FOR_BUILD_ONLY=	tool

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/libdazzle-1.0.pc

# Solaris munmap() uses caddr_t instead of void *
BUILDLINK_TRANSFORM.SunOS+=	rm:-Werror=incompatible-pointer-types

BUILDLINK_DEPMETHOD.gobject-introspection?=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/meson/build.mk"
BUILDLINK_DEPMETHOD.vala?=	build
.include "../../lang/vala/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
