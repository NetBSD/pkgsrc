# $NetBSD: Makefile,v 1.62 2026/01/27 08:39:14 wiz Exp $

DISTNAME=	libkgapi-${KAPPSVER}
PKGREVISION=	12
CATEGORIES=	devel

HOMEPAGE=	https://www.kde.org/
COMMENT=	KDE-based library to access various Google services
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

USE_TOOLS+=	msgmerge

.include "../../devel/kf6-kio/buildlink3.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../misc/kf6-kcontacts/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../time/kf6-kcalendarcore/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
