# $NetBSD: Makefile,v 1.1 2024/05/03 10:09:48 wiz Exp $

DISTNAME=	QXlsx-1.4.7
CATEGORIES=	math
MASTER_SITES=	${MASTER_SITE_GITHUB:=QtExcel/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/QtExcel/QXlsx/
COMMENT=	Excel file reader/writer library using Qt
LICENSE=	mit

USE_LANGUAGES=	c c++
WRKSRC=		${WRKDIR}/${DISTNAME}/QXlsx

.include "../../devel/cmake/build.mk"
.include "../../devel/qt6-qttools/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
