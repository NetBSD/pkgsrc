# $NetBSD: Makefile,v 1.1 2025/05/05 07:28:09 tnn Exp $

DISTNAME=	libportal-0.9.1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=flatpak/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/flatpak/libportal/
COMMENT=	Flatpak portal library
LICENSE=	gnu-lgpl-v3

USE_LANGUAGES=	c c++
USE_TOOLS+=	cmake pkg-config

NOT_FOR_PLATFORM+=	Darwin-*-*

MESON_ARGS+=	-Dbackend-gtk3=disabled
MESON_ARGS+=	-Dbackend-gtk4=disabled
MESON_ARGS+=	-Dbackend-qt5=disabled
MESON_ARGS+=	-Dbackend-qt6=disabled
MESON_ARGS+=	-Dintrospection=false
MESON_ARGS+=	-Ddocs=false
MESON_ARGS+=	-Dtests=false
MESON_ARGS+=	-Dvapi=false

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
#.include "../../devel/gobject-introspection/buildlink3.mk"
#.include "../../x11/gtk3/buildlink3.mk"
#.include "../../x11/gtk4/buildlink3.mk"
#.include "../../x11/qt5-qtbase/buildlink3.mk"
#.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
