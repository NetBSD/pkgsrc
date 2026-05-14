# $NetBSD: Makefile,v 1.23 2026/05/14 16:41:22 ryoon Exp $

DISTNAME=	akonadi-mime-${KAPPSVER}
PKGREVISION=	4
CATEGORIES=	mail

HOMEPAGE=	https://community.kde.org/KDE_PIM
COMMENT=	Libraries and daemons to implement basic email handling
LICENSE=	gnu-lgpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge

.include "../../mail/akonadi/buildlink3.mk"
.include "../../mail/kmime/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
