# $NetBSD: Makefile,v 1.15 2020/06/10 18:08:21 nia Exp $

DISTNAME=	folks-0.14.0
PKGNAME=	lib${DISTNAME}
CATEGORIES=	chat
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/folks/0.14/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/Folks
COMMENT=	Library to manage contacts
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	pkg-config xgettext

MESON_ARGS+=	-Dbluez_backend=false
MESON_ARGS+=	-Deds_backend=false
MESON_ARGS+=	-Dofono_backend=false

PYTHON_FOR_BUILD_ONLY=	tool

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/meson-private/folks.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/folks-dummy.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/folks-telepathy.pc

.include "../../devel/meson/build.mk"
.include "../../chat/telepathy-glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/libgee/buildlink3.mk"
# not compatible with editline
.include "../../devel/readline/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
