# $NetBSD: Makefile,v 1.15 2019/07/21 22:24:00 wiz Exp $

USE_GTK_VERSION=		3
PYTHON_VERSIONS_INCOMPATIBLE=	 36 37 # py-gtk2

PKGREVISION= 9
.include "../../devel/libappindicator/Makefile.common"

MAINTAINER=	pkgsrc-users@NetBSD.org
COMMENT=	GTK+3 Allow applications to export a menu into the panel
PKGNAME=	${DISTNAME:S/-/3-/}

BUILDLINK_TRANSFORM+=	rm:-Werror

DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

.include "../../devel/libindicator3/buildlink3.mk"
.include "../../devel/libdbusmenu-gtk3/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
