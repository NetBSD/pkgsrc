# $NetBSD: Makefile,v 1.30 2021/04/23 19:21:15 nia Exp $

DISTNAME=	breeze-icons-${KF5VER}
PKGREVISION=	1
CATEGORIES=	graphics

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Breeze icon themes
LICENSE=	gnu-lgpl-v2.1 AND gnu-lgpl-v3

.include "../../meta-pkgs/kde/kf5.mk"

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../lang/python/tool.mk"

TOOL_DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

USE_TOOLS+=	bash gsed

LDFLAGS+=	${COMPILER_RPATH_FLAG}${QTDIR}/lib

BUILDLINK_DEPMETHOD.qt5-qtbase= build
.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
