# $NetBSD: Makefile,v 1.8 2020/11/05 09:06:44 ryoon Exp $

DISTNAME=	telepathy-qt-0.9.8
PKGNAME=	${DISTNAME:S/qt/qt5/g}
PKGREVISION=	7
CATEGORIES=	chat
MASTER_SITES=	https://telepathy.freedesktop.org/releases/telepathy-qt/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://telepathy.freedesktop.org/releases/telepathy-qt/
COMMENT=	Qt5 bindings for telepathy
LICENSE=	gnu-lgpl-v2.1

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

PKGCONFIG_OVERRIDE+=	TelepathyQt/TelepathyQt.pc.in
PKGCONFIG_OVERRIDE+=	TelepathyQt/TelepathyQtService.pc.in
PKGCONFIG_OVERRIDE+=	TelepathyQt/Farstream/TelepathyQtFarstream.pc.in

PYTHON_FOR_BUILD_ONLY= yes
.include "../../chat/telepathy-farstream/buildlink3.mk"
.include "../../chat/telepathy-glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/python/tool.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../sysutils/dbus/buildlink3.mk"
.include "../../sysutils/dbus-glib/buildlink3.mk"
BUILDLINK_DEPMETHOD.py-dbus=    build
.include "../../sysutils/py-dbus/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
