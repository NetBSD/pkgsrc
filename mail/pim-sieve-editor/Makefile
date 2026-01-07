# $NetBSD: Makefile,v 1.19 2026/01/07 08:47:49 wiz Exp $

DISTNAME=	pim-sieve-editor-${KAPPSVER}
PKGREVISION=	1
CATEGORIES=	mail

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	Mail sieve editor
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kf6-kdoctools>=6.18.0:../../devel/kf6-kdoctools

USE_TOOLS+=	msgmerge

.include "../../mail/libksieve/buildlink3.mk"
.include "../../misc/kf6-kuserfeedback/buildlink3.mk"
.include "../../security/qt6-qtkeychain/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
