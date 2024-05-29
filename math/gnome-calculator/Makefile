# $NetBSD: Makefile,v 1.72 2024/05/29 16:33:27 adam Exp $

DISTNAME=		gnome-calculator-45.0.2
PKGREVISION=		6
CATEGORIES=		math gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-calculator/${PKGVERSION_NOREV:R:R}/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		prlw1@cam.ac.uk
HOMEPAGE=		https://wiki.gnome.org/Apps/Calculator
COMMENT=		Desktop calculator for GNOME
LICENSE=		gnu-gpl-v2

DEPENDS+=		gnome-icon-theme-symbolic-[0-9]*:../../graphics/gnome-icon-theme-symbolic

CONFLICTS+=		gcalctool-[0-9]*
SUPERSEDES+=		gcalctool-[0-9]*

USE_TOOLS+=		itstool pkg-config

.include "../../devel/glib2/schemas.mk"
.include "../../devel/meson/build.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/libgee/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../math/mpcomplex/buildlink3.mk"
.include "../../math/mpfr/buildlink3.mk"
.include "../../net/libsoup3/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../devel/libadwaita/buildlink3.mk"
.include "../../x11/gtk4/buildlink3.mk"
.include "../../x11/gtksourceview5/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
