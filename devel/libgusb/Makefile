# $NetBSD: Makefile,v 1.1 2026/04/25 13:08:55 vins Exp $

DISTNAME=	libgusb-0.4.9
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=hughsie/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/hughsie/libgusb/
COMMENT=	GObject wrapper for libusb1
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	pkg-config tar

TOOL_DEPENDS+=	${PYPKGPREFIX}-setuptools-[0-9]*:../../devel/py-setuptools

PYTHON_FOR_BUILD_ONLY=	tool

MESON_ARGS+=		-Dumockdev=disabled \
			-Dusb_ids=${PREFIX}/share/hwdata/usb.ids

.include "options.mk"

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/libusb1/buildlink3.mk"
.include "../../textproc/json-glib/buildlink3.mk"
.include "../../sysutils/hwdata/buildlink3.mk"

.include "../../lang/python/pyversion.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
