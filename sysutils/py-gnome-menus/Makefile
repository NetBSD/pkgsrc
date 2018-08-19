# $NetBSD: Makefile,v 1.33 2018/08/19 20:16:41 wiz Exp $

DISTNAME=	gnome-menus-2.30.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	sysutils gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-menus/2.30/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Python bindings for gnome-menus

DISTINFO_FILE=	${.CURDIR}/../gnome-menus/distinfo
PATCHDIR=	${.CURDIR}/../gnome-menus/patches

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_LIBTOOL=		yes

CONFIGURE_ARGS+=	--enable-python
BUILD_DIRS=		python
INSTALL_DIRS=		python
PY_PATCHPLIST=		yes
PYTHON_VERSIONS_INCOMPATIBLE=	34 35 36 37 # not yet ported as of 2.30.5

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.6.0

.include "../../sysutils/gnome-menus/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
