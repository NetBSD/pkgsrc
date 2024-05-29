# $NetBSD: Makefile,v 1.30 2024/05/29 16:34:24 adam Exp $
#

DISTNAME=	dbus-sharp-glib-0.5.0
PKGREVISION=	25
CATEGORIES=	sysutils
MASTER_SITES=	https://cloud.github.com/downloads/mono/dbus-sharp/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/mono/dbus-sharp-glib
COMMENT=	D-Bus for .Net GLib integration module
LICENSE=	mit

GNU_CONFIGURE=	yes
USE_LANGUAGES=	# none
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	dbus-sharp-glib-1.0.pc.in

SUBST_CLASSES+=		fix-mcs
SUBST_STAGE.fix-mcs=	pre-configure
SUBST_MESSAGE.fix-mcs=	Fix compiler name
SUBST_FILES.fix-mcs=	configure
SUBST_SED.fix-mcs=	-e 's,gmcs,mcs,'

.include "../../sysutils/dbus-sharp/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
