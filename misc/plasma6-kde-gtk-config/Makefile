# $NetBSD: Makefile,v 1.2 2025/12/29 10:00:08 markd Exp $

DISTNAME=	kde-gtk-config-${PLASMAVER}
CATEGORIES=	misc

HOMEPAGE=	https://kde.org/plasma-desktop/
COMMENT=	Syncs KDE settings to GTK applications
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/plasma6.mk"

DEPENDS+=	sassc-[0-9]*:../../www/sassc

USE_TOOLS+=	msgmerge pkg-config

REPLACE_SH+=	kconf_update/remove_window_decorations_from_gtk_css.sh

.include "../../devel/kf6-kcolorscheme/buildlink3.mk"
.include "../../devel/kf6-kconfig/buildlink3.mk"
.include "../../devel/kf6-kcoreaddons/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../net/kf6-knewstuff/buildlink3.mk"
.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../sysutils/kf6-kdbusaddons/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/kf6-kguiaddons/buildlink3.mk"
.include "../../x11/kf6-kwindowsystem/buildlink3.mk"
.include "../../x11/plasma6-kdecoration/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
