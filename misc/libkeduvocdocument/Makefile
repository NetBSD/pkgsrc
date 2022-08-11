# $NetBSD: Makefile,v 1.23 2022/08/11 05:09:03 gutteridge Exp $

DISTNAME=	libkeduvocdocument-${KAPPSVER}
PKGREVISION=	8
CATEGORIES=	misc

HOMEPAGE=	https://kde.org/applications/education/
COMMENT=	Common libraries for KDE Edu applications
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

BUILD_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools
DEPENDS+=	kdeedu-data>=${KAPPSVER}:../../misc/kdeedu-data

USE_TOOLS+=	msgmerge

.include "../../devel/kio/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
