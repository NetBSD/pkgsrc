# $NetBSD: Makefile,v 1.34 2023/10/24 22:10:02 wiz Exp $

DISTNAME=	libkeduvocdocument-${KAPPSVER}
PKGREVISION=	1
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
