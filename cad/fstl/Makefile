# $NetBSD: Makefile,v 1.14 2024/11/01 12:51:33 wiz Exp $
#

DISTNAME=	fstl-0.10.0
PKGREVISION=	12
CATEGORIES=	cad
MASTER_SITES=	${MASTER_SITE_GITHUB:=fstl-app/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.mattkeeter.com/projects/fstl/
COMMENT=	Fast STL file viewer
LICENSE=	mit

USE_LANGUAGES=	c c++
USE_CMAKE=	yes

.include "../../x11/qt5-qtbase/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
