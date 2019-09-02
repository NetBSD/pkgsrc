# $NetBSD: Makefile,v 1.16 2019/09/02 13:19:35 adam Exp $

USE_GTK_VERSION=		3
PYTHON_VERSIONS_ACCEPTED=	 27 # py-gtk2

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
