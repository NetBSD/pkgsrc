# $NetBSD: Makefile,v 1.21 2020/06/02 08:23:38 adam Exp $

DISTNAME=	libappindicator-12.10.0
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	https://launchpad.net/libappindicator/12.10/12.10.0/+download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://launchpad.net/libappindicator/
COMMENT=	Allow applications to export a menu into the panel
LICENSE=	gnu-lgpl-v3 AND gnu-lgpl-v2.1

CONFLICTS+=	libappindicator3-[0-9]*
SUPERSEDES+=	libappindicator3-[0-9]*

EXTRACT_USING=	gtar
GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	bindings/mono/appindicator-sharp-0.1.pc.in
PKGCONFIG_OVERRIDE+=	src/appindicator3-0.1.pc.in
PKGCONFIG_OVERRIDE+=	src/appindicator-0.1.pc.in

BUILDLINK_TRANSFORM+=	rm:-Werror

CONFIGURE_ARGS+=	--with-gtk=3

DEPENDS+=	${PYPKGPREFIX}-gobject3-[0-9]*:../../devel/py-gobject3

PYTHON_VERSIONS_ACCEPTED=	27 # py-gtk2

.include "../../devel/libindicator/buildlink3.mk"
.include "../../devel/libdbusmenu-gtk3/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
