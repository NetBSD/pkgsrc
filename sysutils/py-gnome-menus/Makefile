# $NetBSD: Makefile,v 1.13 2008/05/29 16:07:07 drochner Exp $
#

DISTNAME=	gnome-menus-2.22.2
PKGNAME=	${PYPKGPREFIX}-gnome-menus-2.22.2
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-menus/2.22/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	drochner@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Python bindings for gnome-menus

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--enable-python
BUILD_DIRS=		python
INSTALL_DIRS=		python
PY_PATCHPLIST=		yes

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.6.0

.include "../../sysutils/gnome-menus/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/fam.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
