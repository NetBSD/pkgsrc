# $NetBSD: Makefile,v 1.12 2021/04/14 07:28:18 wiz Exp $

DISTNAME=	libhandy-v0.0.13
PKGNAME=	${DISTNAME:S/-v/-/1}
PKGREVISION=	6
CATEGORIES=	devel
MASTER_SITES=	https://source.puri.sm/Librem5/libhandy/-/archive/v${PKGVERSION_NOREV}/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://source.puri.sm/Librem5/libhandy
COMMENT=	Library with GTK+3 widgets for mobile devices
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config

# workaround for build failure
# https://gitlab.gnome.org/GNOME/json-glib/issues/35
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/src

PYTHON_FOR_BUILD_ONLY=	tool

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/libhandy-0.0.pc

BUILDLINK_DEPMETHOD.gobject-introspection?=	build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/meson/build.mk"
BUILDLINK_DEPMETHOD.vala?=	build
.include "../../lang/vala/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
