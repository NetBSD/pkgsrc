# $NetBSD: Makefile,v 1.71 2023/11/12 13:21:15 wiz Exp $

DISTNAME=	ghex-3.18.4
PKGREVISION=	10
CATEGORIES=	editors gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/ghex/3.18/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Apps/Ghex
COMMENT=	Hex editor
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config msgfmt itstool

PYTHON_FOR_BUILD_ONLY=	tool

PKGCONFIG_OVERRIDE_STAGE=	pre-install
PKGCONFIG_OVERRIDE+=		output/data/gtkhex-3.pc

.include "../../devel/meson/build.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
