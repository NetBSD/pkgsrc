# $NetBSD: Makefile,v 1.3 2024/08/12 14:03:25 adam Exp $

DISTNAME=	QXlsx-1.4.9
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

.include "../../devel/cmake/build.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
