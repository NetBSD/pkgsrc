# $NetBSD: Makefile,v 1.2 2024/05/29 16:34:36 adam Exp $

DISTNAME=	syntax-highlighting-${KF6VER}
PKGREVISION=	1
CATEGORIES=	textproc

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Syntax highlighting engine for structured text and code
LICENSE=	gnu-lgpl-v2.1

.include "../../meta-pkgs/kde/kf6.mk"

USE_TOOLS+=	perl pkg-config

CHECK_PORTABILITY_SKIP+=	autotests/input/highlight.sh
CHECK_PORTABILITY_SKIP+=	autotests/folding/highlight.sh.fold

.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../lang/qt6-qtdeclarative/buildlink3.mk"
.include "../../textproc/xerces-c/buildlink3.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/atomic64.mk"
.include "../../mk/bsd.pkg.mk"
