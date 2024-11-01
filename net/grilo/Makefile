# $NetBSD: Makefile,v 1.62 2024/11/01 00:53:05 wiz Exp $

DISTNAME=	grilo-0.3.16
PKGREVISION=	1
CATEGORIES=	net gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/${PKGBASE}/${PKGVERSION_NOREV:R}/}
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
.include "../../net/libsoup3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
