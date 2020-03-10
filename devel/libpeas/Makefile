# $NetBSD: Makefile,v 1.47 2020/03/10 22:30:30 wiz Exp $

DISTNAME=	libpeas-1.26.0
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libpeas/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/Libpeas
COMMENT=	GObject-based plugins engine
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=		intltool msgfmt pkg-config

PKGCONFIG_OVERRIDE+=	output/meson-private/libpeas-gtk-1.0.pc
PKGCONFIG_OVERRIDE+=	output/meson-private/libpeas-1.0.pc

PKGCONFIG_OVERRIDE_STAGE=	post-configure

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/libpeas:${WRKSRC}/output/libpeas-gtk:${WRKSRC}/output/tests/libpeas/introspection

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.38.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=1.39.0
.include "../../devel/gobject-introspection/buildlink3.mk"
#.include "../../devel/py-gobject3-common/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
