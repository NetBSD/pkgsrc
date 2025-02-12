# $NetBSD: Makefile,v 1.20 2025/02/12 06:45:16 ryoon Exp $

DISTNAME=	ktnef-${KAPPSVER}
PKGREVISION=	7
CATEGORIES=	mail

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	API for handling TNEF data
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../misc/kcontacts/buildlink3.mk"
.include "../../time/kcalutils/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
