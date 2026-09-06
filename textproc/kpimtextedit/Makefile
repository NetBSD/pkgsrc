# $NetBSD: Makefile,v 1.57 2026/09/06 11:03:07 markd Exp $

DISTNAME=	kpimtextedit-${KAPPSVER}
CATEGORIES=	textproc

HOMEPAGE=	https://community.kde.org/KDE_PIM
COMMENT=	Textedit with PIM-specific features
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../textproc/ktextaddons/buildlink3.mk"
.include "../../textproc/kf6-syntax-highlighting/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
