# $NetBSD: Makefile,v 1.11 2024/11/01 12:53:22 wiz Exp $

DISTNAME=	mbox-importer-${KAPPSVER}
PKGREVISION=	5
CATEGORIES=	mail

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	Import mbox files to KMail
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

USE_TOOLS+=	msgmerge

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mail/mailcommon/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
