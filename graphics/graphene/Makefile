# $NetBSD: Makefile,v 1.11 2026/09/02 19:02:39 wiz Exp $

DISTNAME=	graphene-1.10.8
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=ebassi/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://ebassi.github.io/graphene/
COMMENT=	Thin layer of graphic data types
LICENSE=	mit

TOOL_DEPENDS+=	glib2-introspection-[0-9]*:../../devel/glib2-introspection

USE_TOOLS+=	pkg-config

MESON_ARGS+=	-Dgobject_types=true
MESON_ARGS+=	-Dintrospection=enabled
MESON_ARGS+=	-Dtests=false
MESON_ARGS+=	-Dinstalled_tests=false

CFLAGS.SunOS+=	-D__EXTENSIONS__

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
