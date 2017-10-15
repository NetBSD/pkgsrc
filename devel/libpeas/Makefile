# $NetBSD: Makefile,v 1.33 2017/10/15 23:19:11 prlw1 Exp $

DISTNAME=	libpeas-1.20.0
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libpeas/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/Libpeas
COMMENT=	GObject-based plugins engine
LICENSE=	gnu-lgpl-v2.1

USE_PKGLOCALEDIR=	yes

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake intltool msgfmt pkg-config gsed

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../lang/python/pyversion.mk"
CONFIGURE_ARGS+=	--disable-python2
CONFIGURE_ENV+=		PYTHON3_CONFIG=${PYTHONCONFIG}
CONFIGURE_ARGS+=	--disable-lua5.1 # looks for lua5.1.pc
CONFIGURE_ARGS+=	--disable-luajit


PKGCONFIG_OVERRIDE+=	data/libpeas-gtk-1.0.pc.in
PKGCONFIG_OVERRIDE+=	data/libpeas-1.0.pc.in

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.38.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=1.39.0
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/py-gobject3/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
