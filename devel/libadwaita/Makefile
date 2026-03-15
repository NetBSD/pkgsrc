# $NetBSD: Makefile,v 1.36 2026/03/15 09:41:20 wiz Exp $

DISTNAME=	libadwaita-1.8.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/${PKGBASE}/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/GNOME/libadwaita/
COMMENT=	Building blocks for modern GNOME applications
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	sassc-[0-9]*:../../www/sassc

USE_TOOLS+=	msgfmt pkg-config

PKGCONFIG_OVERRIDE+=	output/meson-private/libadwaita-1.pc

PKGCONFIG_OVERRIDE_STAGE=	post-configure

TEST_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/src

.include "../../devel/appstream/buildlink3.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
BUILDLINK_API_DEPENDS.gtk4+=	gtk4>=4.19.4
.include "../../x11/gtk4/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
