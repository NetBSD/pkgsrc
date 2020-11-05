# $NetBSD: Makefile,v 1.11 2020/11/05 09:07:10 ryoon Exp $

DISTNAME=	kpimtextedit-${KAPPSVER}
PKGREVISION=	3
CATEGORIES=	textproc

HOMEPAGE=	https://community.kde.org/KDE_PIM
COMMENT=	Textedit with PIM-specific features
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

DEPENDS+=	kdesignerplugin-[0-9]*:../../x11/kdesignerplugin

USE_TOOLS+=	msgmerge

.include "../../devel/grantlee-qt5/buildlink3.mk"
.include "../../devel/kio/buildlink3.mk"
.include "../../misc/kemoticons/buildlink3.mk"
.include "../../textproc/syntax-highlighting/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../x11/qt5-qtspeech/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
