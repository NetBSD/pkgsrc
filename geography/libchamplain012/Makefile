# $NetBSD: Makefile,v 1.33 2020/11/05 09:06:53 ryoon Exp $

DISTNAME=	libchamplain-0.12.20
PKGNAME=	${DISTNAME:S/ain/ain012/}
PKGREVISION=	4
CATEGORIES=	geography
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libchamplain/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://projects.gnome.org/libchamplain
COMMENT=	Map widget
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config
MESON_ARGS+=	-Dmemphis=true

PKGCONFIG_OVERRIDE_STAGE=	post-configure
PKGCONFIG_OVERRIDE+=		output/meson-private/champlain-0.12.pc
PKGCONFIG_OVERRIDE+=		output/meson-private/champlain-gtk-0.12.pc

# TODO:
# add vala option?
# add introspection option?

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../geography/libmemphis02/buildlink3.mk"
.include "../../graphics/clutter-gtk/buildlink3.mk"
.include "../../graphics/clutter/buildlink3.mk"
.include "../../net/libsoup/buildlink3.mk"
.include "../../textproc/gtk-doc/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
