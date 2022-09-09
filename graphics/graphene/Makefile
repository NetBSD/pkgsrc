# $NetBSD: Makefile,v 1.6 2022/09/09 15:21:13 wiz Exp $

DISTNAME=	graphene-1.10.8
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=ebassi/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://ebassi.github.io/graphene/
COMMENT=	Thin layer of graphic data types
LICENSE=	mit

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
