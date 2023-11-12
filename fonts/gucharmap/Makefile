# $NetBSD: Makefile,v 1.120 2023/11/12 13:21:26 wiz Exp $

DISTNAME=	gucharmap-15.1.2
PKGREVISION=	1
CATEGORIES=	fonts gnome
MASTER_SITES=	https://gitlab.gnome.org/GNOME/gucharmap/-/archive/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/action/show/Apps/Gucharmap
COMMENT=	Unicode/ISO10646 character map and font viewer
LICENSE=	gnu-gpl-v3 AND unicode

TOOL_DEPENDS+=	gtk-doc-[0-9]*:../../textproc/gtk-doc
DEPENDS+=	unicode-character-database-[0-9]*:../../textproc/unicode-character-database

MESON_ARGS+=	-Ducd_path=${PREFIX}/share/unicode/ucd

USE_TOOLS+=		itstool perl pkg-config

PKGCONFIG_OVERRIDE+=		output/meson-private/gucharmap-2.90.pc
PKGCONFIG_OVERRIDE_STAGE=	post-build

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../x11/gtk3/modules.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../lang/python/tool.mk"
.include "../../mk/bsd.pkg.mk"
