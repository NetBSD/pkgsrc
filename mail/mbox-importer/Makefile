# $NetBSD: Makefile,v 1.22 2026/05/14 16:41:25 ryoon Exp $

DISTNAME=	mbox-importer-${KAPPSVER}
PKGREVISION=	4
CATEGORIES=	mail

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	Import mbox files to KMail
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../mail/mailcommon/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
