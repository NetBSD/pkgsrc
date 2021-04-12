# $NetBSD: Makefile,v 1.3 2021/04/12 13:23:36 nia Exp $

DISTNAME=	graphene-1.10.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=ebassi/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://ebassi.github.io/graphene/
COMMENT=	Thin layer of graphic data types
LICENSE=	mit

USE_TOOLS+=	pkg-config

MESON_ARGS+=	-Dgobject_types=true
MESON_ARGS+=	-Dintrospection=true
MESON_ARGS+=	-Dtests=false
MESON_ARGS+=	-Dinstalled_tests=false

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
