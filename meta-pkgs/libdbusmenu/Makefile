# $NetBSD: Makefile,v 1.3 2017/02/06 13:54:46 wiz Exp $
#

META_PACKAGE=	yes

PKGREVISION= 2
.include "Makefile.common"

DEPENDS+=	libdbusmenu-glib>=${PKGVERSION_NOREV}:../../devel/libdbusmenu-glib
DEPENDS+=	libdbusmenu-gtk>=${PKGVERSION_NOREV}:../../devel/libdbusmenu-gtk
DEPENDS+=	libdbusmenu-gtk3>=${PKGVERSION_NOREV}:../../devel/libdbusmenu-gtk3
DEPENDS+=	libdbusmenu-gtk-doc>=${PKGVERSION_NOREV}:../../devel/libdbusmenu-gtk-doc
DEPENDS+=	libdbusmenu-jsonloader>=${PKGVERSION_NOREV}:../../devel/libdbusmenu-jsonloader
DEPENDS+=	libdbusmenu-tools>=${PKGVERSION_NOREV}:../../devel/libdbusmenu-tools

.include "../../mk/bsd.pkg.mk"
