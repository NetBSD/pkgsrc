# $NetBSD: Makefile,v 1.123 2024/05/29 16:32:02 adam Exp $

DISTNAME=		glade-3.40.0
PKGREVISION=		11
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/glade/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://glade.gnome.org/
COMMENT=		User interface builder for the GTK3+ toolkit
LICENSE=		gnu-gpl-v2

TOOL_DEPENDS+=		libxslt-[0-9]*:../../textproc/libxslt
TOOL_DEPENDS+=		docbook-xsl-[0-9]*:../../textproc/docbook-xsl

USE_TOOLS+=		itstool msgfmt pkg-config

# error: 'for' loop initial declarations are only allowed in C99 mode
FORCE_C_STD=		c99

PKGCONFIG_OVERRIDE+=	data/gladeui-2.0.pc.in

.include "../../devel/meson/build.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
