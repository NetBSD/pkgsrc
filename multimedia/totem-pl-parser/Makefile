# $NetBSD: Makefile,v 1.75 2020/06/13 17:55:40 nia Exp $

DISTNAME=	totem-pl-parser-3.26.5
CATEGORIES=	multimedia gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/totem-pl-parser/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Apps/Videos
COMMENT=	Totem playlist parser
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	pkg-config xgettext

MESON_ARGS+=	-Denable-quvi=no

# workaround for build failure
# https://gitlab.gnome.org/GNOME/json-glib/issues/35
MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/plparse

PYTHON_FOR_BUILD_ONLY=	tool

PKGCONFIG_OVERRIDE+=	totem-plparser-mini.pc.in
PKGCONFIG_OVERRIDE+=	totem-plparser.pc.in

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../archivers/libarchive/buildlink3.mk"
.include "../../security/libgcrypt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
