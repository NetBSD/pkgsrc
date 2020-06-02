# $NetBSD: Makefile,v 1.138 2020/06/02 08:22:43 adam Exp $

DISTNAME=	kipi-plugins-${KAPPSVER}
PKGREVISION=	4
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
