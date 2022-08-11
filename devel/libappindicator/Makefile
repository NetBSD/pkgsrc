# $NetBSD: Makefile,v 1.29 2022/08/11 05:08:11 gutteridge Exp $

DISTNAME=	libappindicator-12.10.0
PKGREVISION=	12
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

PYTHON_VERSIONS_ACCEPTED=	27 # py-gtk2

# When building with GTK3 support, the Python bindings are not ever generated.
# However, the configure script still refuses to work if a Python 2
# interpreter is not available... This might be fixed in version control
# snapshots beyond 12.10.0.
PYTHON_FOR_BUILD_ONLY=		yes

.include "../../devel/libindicator/buildlink3.mk"
.include "../../devel/libdbusmenu-gtk3/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../lang/python/extension.mk"
.include "../../x11/gtk3/buildlink3.mk"
BUILDLINK_DEPMETHOD.pygtk2=	build
.include "../../x11/py-gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
