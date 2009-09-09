# $NetBSD: Makefile,v 1.8 2009/09/09 11:16:56 wiz Exp $
#

DISTNAME=	telepathy-gabble-0.7.21
CATEGORIES=	chat
MASTER_SITES=	http://telepathy.freedesktop.org/releases/telepathy-gabble/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://telepathy.freedesktop.org/wiki/Components
COMMENT=	Jabber/XMPP connection manager for Telepathy

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config

.include "../../lang/python/pyversion.mk"
.if ${PYPKGPREFIX} == "py24"
BUILD_DEPENDS+=		${PYPKGPREFIX}-expat-[0-9]*:../../textproc/py-expat
.endif
CONFIGURE_ENV+=		ac_cv_prog_PYTHON=${PYTHONBIN}

BUILDLINK_API_DEPENDS.telepathy-glib+=	telepathy-glib>=0.7.23
.include "../../chat/telepathy-glib/buildlink3.mk"
BUILDLINK_API_DEPENDS.loudmouth+=	loudmouth>=1.3.2
.include "../../chat/loudmouth/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=		glib2>=2.16.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/application.mk"
BUILDLINK_API_DEPENDS.dbus-glib+=	dbus-glib>=0.78
.include "../../sysutils/dbus-glib/buildlink3.mk"
BUILDLINK_API_DEPENDS.dbus+=		dbus>=1.1
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
