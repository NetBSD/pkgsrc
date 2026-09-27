# $NetBSD: Makefile,v 1.28 2026/09/27 11:37:22 tnn Exp $

DISTNAME=	akonadi-mime-${KAPPSVER}
PKGREVISION=	1
CATEGORIES=	mail

HOMEPAGE=	https://community.kde.org/KDE_PIM
COMMENT=	Libraries and daemons to implement basic email handling
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge

.include "../../mail/akonadi/buildlink3.mk"
.include "../../mail/kf6-kmime/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
