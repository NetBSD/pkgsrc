# $NetBSD: Makefile,v 1.1 2020/09/04 11:21:41 prlw1 Exp $

DISTNAME=	graphene-1.10.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=ebassi/graphene/releases/download/${PKGVERSION_NOREV:R}/}
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

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
