# $NetBSD: Makefile,v 1.9 2022/07/17 21:23:31 wiz Exp $

DISTNAME=	spice-gtk-0.41
CATEGORIES=	sysutils
MASTER_SITES=	https://www.spice-space.org/download/gtk/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.spice-space.org/spice-gtk.html
COMMENT=	GTK+ widget for SPICE clients
LICENSE=	gnu-lgpl-v2.1

DEPENDS+=	${PYPKGPREFIX}-pyparsing-[0-9]*:../../devel/py-pyparsing
DEPENDS+=	${PYPKGPREFIX}-six-[0-9]*:../../lang/py-six
BUILD_DEPENDS+=	gtk-doc-[0-9]*:../../textproc/gtk-doc
BUILD_DEPENDS+=	asciidoc-[0-9]*:../../textproc/asciidoc

USE_TOOLS+=		pkg-config
USE_PKGLOCALEDIR=	yes

PKGCONFIG_OVERRIDE+=	spice-client-glib-2.0.pc.in
PKGCONFIG_OVERRIDE+=	spice-client-gtk-3.0.pc.in

MESON_ARGS+=		-Dintrospection=enabled
MESON_ARGS+=		-Dvapi=enabled

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../lang/python/pyversion.mk"
.include "../../lang/python/tool.mk"
.include "../../audio/libopus/buildlink3.mk"
.include "../../multimedia/gst-plugins1-base/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
BUILDLINK_API_DEPENDS.spice-protocol+=	spice-protocol>=0.14.1
.include "../../sysutils/spice-protocol/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/pixman/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
