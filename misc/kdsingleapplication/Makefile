# $NetBSD: Makefile,v 1.1 2026/05/19 14:32:28 adam Exp $

DISTNAME=	KDSingleApplication-1.2.1
PKGNAME=	${DISTNAME:tl}
CATEGORIES=	misc
MASTER_SITES=	${MASTER_SITE_GITHUB:=KDAB/}
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/KDAB/KDSingleApplication
COMMENT=	Helper class for single-instance policy applications
LICENSE=	mit

#WRKSRC=		${WRKDIR}/KDSingleApplication-1.2.0
USE_CXX_FEATURES=	c++11
USE_LANGUAGES=		c++

.include "../../devel/cmake/build.mk"
.include "../../x11/qt6-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
