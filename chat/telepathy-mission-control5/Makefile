# $NetBSD: Makefile,v 1.12 2012/10/03 00:02:45 asau Exp $
#

DISTNAME=	telepathy-mission-control-5.7.9
PKGNAME=	telepathy-mission-control5-5.7.9
PKGREVISION=	6
CATEGORIES=	chat
#MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=mission-control/}
MASTER_SITES=	http://telepathy.freedesktop.org/releases/telepathy-mission-control/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://mission-control.sourceforge.net/
COMMENT=	Telepathy component providing abstractions for "end-user" applications

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

PKGCONFIG_OVERRIDE+=	mission-control-plugins.pc.in
#PKGCONFIG_OVERRIDE+=	libmcclient.pc.in
#PKGCONFIG_OVERRIDE+=	mission-control.pc.in

#.include "../../lang/python/pyversion.mk"
CONFIGURE_ENV+=		ac_cv_prog_PYTHON=${PYTHONBIN}

CONFIGURE_ARGS+= --enable-gnome-keyring
.include "../../security/libgnome-keyring/buildlink3.mk"

# needs py-twisted
# TEST_TARGET= check

BUILD_DEPENDS+=	${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat

.include "../../chat/telepathy-glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/application.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
