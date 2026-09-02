# $NetBSD: Makefile,v 1.16 2026/09/02 19:03:21 wiz Exp $

DISTNAME=	QXlsx-1.5.1.1
PKGREVISION=	2
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=QtExcel/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/QtExcel/QXlsx
COMMENT=	Excel file reader/writer library using Qt
LICENSE=	mit

USE_CXX_FEATURES=	c++17
USE_LANGUAGES=		c c++
CONFIGURE_DIR=		QXlsx
CMAKE_CONFIGURE_ARGS+=	-DBUILD_SHARED_LIBS=ON

.include "../../devel/cmake/build.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
