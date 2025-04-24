# $NetBSD: Makefile,v 1.58 2025/04/24 14:13:38 wiz Exp $

DISTNAME=	libkgapi-${KAPPSVER}
PKGREVISION=	9
CATEGORIES=	devel

HOMEPAGE=	https://www.kde.org/
COMMENT=	KDE-based library to access various Google services
LICENSE=	gnu-lgpl-v2 AND gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

CFLAGS.NetBSD+=	-D_NETBSD_SOURCE

USE_TOOLS+=	msgmerge

.include "../../devel/kio/buildlink3.mk"
.include "../../misc/kcontacts/buildlink3.mk"
.include "../../security/cyrus-sasl/buildlink3.mk"
.include "../../time/kcalendarcore/buildlink3.mk"
.include "../../x11/qt5-qtwebengine/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
