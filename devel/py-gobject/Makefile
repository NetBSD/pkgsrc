# $NetBSD: Makefile,v 1.5 2006/04/12 09:28:00 drochner Exp $
#

DISTNAME=		pygobject-2.10.1
PKGNAME=		${PYPKGPREFIX}-gobject-2.10.1
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/pygobject/2.10/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://www.pygtk.org/
COMMENT=		Python bindings for glib2 gobject

USE_PKGLOCALEDIR=	yes
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ENV+=		PYTHON=${PYTHONBIN:Q}

PKGCONFIG_OVERRIDE+=	pygobject-2.0.pc.in
PYTHON_VERSIONS_ACCEPTED= 24 23
PY_PATCHPLIST=		yes
CONFLICTS+=		${PYPKGPREFIX}-gtk2<2.8.4

.include "../../lang/python/extension.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
