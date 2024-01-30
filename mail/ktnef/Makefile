# $NetBSD: Makefile,v 1.12 2024/01/30 14:22:13 ryoon Exp $

DISTNAME=	ktnef-${KAPPSVER}
PKGREVISION=	4
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
