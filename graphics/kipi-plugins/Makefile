# $NetBSD: Makefile,v 1.146 2021/04/07 12:28:24 markd Exp $

DISTNAME=	kipi-plugins-${KAPPSVER}
CATEGORIES=	graphics

HOMEPAGE=	https://userbase.kde.org/KIPI/
COMMENT=	Collection of plugins extending the KDE graphics and image applications
LICENSE=	gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge pkg-config

.include "../../devel/kio/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/libkipi/buildlink3.mk"
.include "../../misc/libkvkontakte/buildlink3.mk"
.include "../../www/libmediawiki/buildlink3.mk"
.include "../../x11/kxmlgui/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
