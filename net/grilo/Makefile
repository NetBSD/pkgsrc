# $NetBSD: Makefile,v 1.33 2020/04/12 08:28:02 adam Exp $

DISTNAME=	grilo-0.3.11
PKGREVISION=	3
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/grilo/0.3/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/Grilo
COMMENT=	Media browser framework
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	pkg-config xgettext

MESON_ARGS+=	-Denable-gtk-doc=false
MESON_ARGS+=	-Denable-test-ui=false

PYTHON_FOR_BUILD_ONLY=	tool

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/grilo-0.3.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/grilo-net-0.3.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/grilo-pls-0.3.pc

.include "../../devel/meson/build.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../multimedia/totem-pl-parser/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../security/liboauth/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
