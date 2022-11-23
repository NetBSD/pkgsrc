# $NetBSD: Makefile,v 1.10 2022/11/23 16:19:34 adam Exp $

DISTNAME=	gom-0.4
PKGREVISION=	8
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gom/0.4/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/Gom
COMMENT=	Object mapper from GObjects to SQLite
LICENSE=	gnu-lgpl-v2.1

BUILD_DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

USE_LANGUAGES+=	c
USE_TOOLS+=	pkg-config

PY_PATCHPLIST=	yes

PYTHON_VERSIONS_INCOMPATIBLE=	27

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
