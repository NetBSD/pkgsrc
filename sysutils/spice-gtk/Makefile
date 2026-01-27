# $NetBSD: Makefile,v 1.32 2026/01/27 08:40:38 wiz Exp $

DISTNAME=	spice-gtk-0.42
PKGREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	https://www.spice-space.org/download/gtk/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.spice-space.org/spice-gtk.html
COMMENT=	GTK+ widget for SPICE clients
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-pyparsing-[0-9]*:../../devel/py-pyparsing
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
TOOL_DEPENDS+=	gtk-doc-[0-9]*:../../textproc/gtk-doc
TOOL_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

USE_TOOLS+=		msgfmt pkg-config
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	spice-client-glib-2.0.pc.in
PKGCONFIG_OVERRIDE+=	spice-client-gtk-3.0.pc.in

MESON_ARGS+=		-Dintrospection=enabled
MESON_ARGS+=		-Dvapi=enabled

MAKE_ENV+=	LD_LIBRARY_PATH=${WRKSRC}/output/src
# For Darwin
MAKE_ENV+=	DYLD_LIBRARY_PATH=${WRKSRC}/output/src

REPLACE_PYTHON=	subprojects/keycodemapdb/tools/keymap-gen

.include "../../audio/libopus/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../lang/python/application.mk"
.include "../../lang/python/tool.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
BUILDLINK_API_DEPENDS.spice-protocol+=	spice-protocol>=0.14.1
.include "../../sysutils/spice-protocol/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
