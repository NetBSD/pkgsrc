# $NetBSD: Makefile,v 1.52 2024/12/05 09:43:29 markd Exp $

DISTNAME=	breeze-icons-${KF6VER}
PKGNAME=	${DISTNAME}
CATEGORIES=	graphics

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Breeze icon themes
LICENSE=	gnu-lgpl-v2.1 AND gnu-lgpl-v3

.include "../../meta-pkgs/kde/kf6.mk"

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../lang/python/tool.mk"

TOOL_DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

USE_TOOLS+=	bash gsed

LDFLAGS+=	${COMPILER_RPATH_FLAG}${QTDIR}/lib

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
