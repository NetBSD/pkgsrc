# $NetBSD: Makefile,v 1.6 2024/11/14 22:21:51 wiz Exp $

DISTNAME=	ktexttemplate-${KF6VER}
PKGREVISION=	4
CATEGORIES=	textproc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Separate the structure of documents from the data they contain
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf6.mk"

.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
