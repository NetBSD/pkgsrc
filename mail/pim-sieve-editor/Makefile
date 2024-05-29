# $NetBSD: Makefile,v 1.8 2024/05/29 16:33:24 adam Exp $

DISTNAME=	pim-sieve-editor-${KAPPSVER}
PKGREVISION=	2
CATEGORIES=	mail

HOMEPAGE=	https://kontact.kde.org/
COMMENT=	Mail sieve editor
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

.include "../../meta-pkgs/kde/applications.mk"

TOOL_DEPENDS+=	kdoctools>=5.19.0:../../devel/kdoctools

USE_TOOLS+=	msgmerge

.include "../../devel/boost-headers/buildlink3.mk"
.include "../../mail/libksieve/buildlink3.mk"
.include "../../misc/kuserfeedback/buildlink3.mk"
.include "../../security/qt5-qtkeychain/buildlink3.mk"
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
