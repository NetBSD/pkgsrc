# $NetBSD: Makefile,v 1.38 2020/03/08 16:51:22 wiz Exp $

DISTNAME=	gnome-menus-2.30.5
PKGNAME=	${PYPKGPREFIX}-${DISTNAME}
PKGREVISION=	5
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

CONFIGURE_ARGS+=		--enable-python
BUILD_DIRS=			python
INSTALL_DIRS=			python
PY_PATCHPLIST=			yes
PYTHON_VERSIONS_ACCEPTED=	27 # not yet ported as of 2.30.5

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.6.0

.include "../../sysutils/gnome-menus/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
