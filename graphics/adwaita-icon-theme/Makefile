# $NetBSD: Makefile,v 1.29 2026/06/09 17:09:12 wiz Exp $

DISTNAME=		adwaita-icon-theme-50.0
CATEGORIES=		graphics gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/adwaita-icon-theme/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		prlw1@cam.ac.uk
HOMEPAGE=		https://www.gnome.org/
COMMENT=		Standard GNOME icons
LICENSE=		cc-by-sa-v3.0 OR gnu-lgpl-v3

USE_TOOLS+=		pkg-config
TOOLS_NOOP+=		gtk-update-icon-cache

# not necessary
#PKGCONFIG_OVERRIDE+=	adwaita-icon-theme.pc.in

ICON_THEMES=		yes

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
