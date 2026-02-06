# $NetBSD: Makefile,v 1.61 2026/02/06 10:04:57 wiz Exp $

DISTNAME=	breeze-icons-${KF6VER}
PKGNAME=	${DISTNAME}
PKGREVISION=	3
CATEGORIES=	graphics

HOMEPAGE=	https://community.kde.org/Frameworks
COMMENT=	Breeze icon themes
LICENSE=	gnu-lgpl-v2.1 AND gnu-lgpl-v3

# causes core dumps as of 6.18 on NetBSD 11.99.3/gcc 14
BUILDLINK_TRANSFORM.NetBSD+=	rm:-fno-lto

.include "../../meta-pkgs/kde/kf6.mk"

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../lang/python/tool.mk"

TOOL_DEPENDS+=	${PYPKGPREFIX}-lxml-[0-9]*:../../textproc/py-lxml

USE_TOOLS+=	bash gsed

LDFLAGS+=	${COMPILER_RPATH_FLAG}${QTDIR}/lib

.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
