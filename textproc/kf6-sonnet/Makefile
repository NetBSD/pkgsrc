# $NetBSD: Makefile,v 1.6 2024/12/05 09:43:26 markd Exp $

DISTNAME=	sonnet-${KF6VER}
CATEGORIES=	textproc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Spelling framework for Qt6
LICENSE=	gnu-lgpl-v2.1

USE_TOOLS+=	pkg-config

.include "../../meta-pkgs/kde/kf6.mk"

.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../textproc/aspell/buildlink3.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
