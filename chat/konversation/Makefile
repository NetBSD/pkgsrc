# $NetBSD: Makefile,v 1.135 2024/05/29 16:31:30 adam Exp $

DISTNAME=	konversation-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	chat

HOMEPAGE=	https://konversation.kde.org/
COMMENT=	KDE IRC Client
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge perl pkg-config

REPLACE_BASH+=		data/scripts/*
REPLACE_PERL+=		data/updaters/konversation-*.pl
REPLACE_PERL+=		data/scripts/*
REPLACE_PYTHON+=	data/scripts/*
REPLACE_PYTHON+=	data/scripting_support/python/konversation/dbus.py

USE_TOOLS+=		bash:run

.include "../../lang/python/application.mk"
.include "../../devel/kidletime/buildlink3.mk"
.include "../../devel/knotifyconfig/buildlink3.mk"
.include "../../devel/kparts/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/knewstuff/buildlink3.mk"
.include "../../security/qca2-qt5/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
