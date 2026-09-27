# $NetBSD: Makefile,v 1.3 2026/09/27 11:37:37 tnn Exp $

DISTNAME=	KDSingleApplication-1.2.1
PKGNAME=	${DISTNAME:tl}
PKGREVISION=	2
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
