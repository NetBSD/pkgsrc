# $NetBSD: Makefile,v 1.16 2023/11/08 13:18:23 wiz Exp $

DISTNAME=	gom-0.4
PKGREVISION=	13
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gom/0.4/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/Gom
COMMENT=	Object mapper from GObjects to SQLite
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

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
