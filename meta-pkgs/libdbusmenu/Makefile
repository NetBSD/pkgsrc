# $NetBSD: Makefile,v 1.6 2018/03/12 11:15:39 wiz Exp $
#

META_PACKAGE=	yes

PKGREVISION= 5
.include "Makefile.common"

DEPENDS+=	libdbusmenu-glib>=${PKGVERSION_NOREV}:../../devel/libdbusmenu-glib
DEPENDS+=	libdbusmenu-gtk>=${PKGVERSION_NOREV}:../../devel/libdbusmenu-gtk
DEPENDS+=	libdbusmenu-gtk3>=${PKGVERSION_NOREV}:../../devel/libdbusmenu-gtk3
DEPENDS+=	libdbusmenu-gtk-doc>=${PKGVERSION_NOREV}:../../devel/libdbusmenu-gtk-doc
DEPENDS+=	libdbusmenu-jsonloader>=${PKGVERSION_NOREV}:../../devel/libdbusmenu-jsonloader
DEPENDS+=	libdbusmenu-tools>=${PKGVERSION_NOREV}:../../devel/libdbusmenu-tools

.include "../../mk/bsd.pkg.mk"
