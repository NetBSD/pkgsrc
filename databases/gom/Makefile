# $NetBSD: Makefile,v 1.28 2026/09/02 19:01:15 wiz Exp $

DISTNAME=	gom-0.4
PKGREVISION=	24
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gom/0.4/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/Gom
COMMENT=	Object mapper from GObjects to SQLite
LICENSE=	gnu-lgpl-v2.1

TOOL_DEPENDS+=	glib2-introspection-[0-9]*:../../devel/glib2-introspection
TOOL_DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

USE_LANGUAGES+=	c
USE_TOOLS+=	pkg-config

PY_PATCHPLIST=	yes

.include "../../databases/sqlite3/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../mk/bsd.pkg.mk"
