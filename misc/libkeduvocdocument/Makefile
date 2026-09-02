# $NetBSD: Makefile,v 1.55 2026/09/02 19:03:34 wiz Exp $

DISTNAME=	libkeduvocdocument-${KAPPSVER}
PKGREVISION=	6
CATEGORIES=	misc

HOMEPAGE=	https://kde.org/applications/education/
COMMENT=	Common libraries for KDE Edu applications
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools
DEPENDS+=	kdeedu-data>=${KAPPSVER}:../../misc/kdeedu-data

USE_TOOLS+=	msgmerge

.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
