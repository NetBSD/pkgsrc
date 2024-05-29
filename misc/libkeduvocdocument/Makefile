# $NetBSD: Makefile,v 1.40 2024/05/29 16:33:38 adam Exp $

DISTNAME=	libkeduvocdocument-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	misc

HOMEPAGE=	https://kde.org/applications/education/
COMMENT=	Common libraries for KDE Edu applications
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools
DEPENDS+=	kdeedu-data>=${KAPPSVER}:../../misc/kdeedu-data

USE_TOOLS+=	msgmerge

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
