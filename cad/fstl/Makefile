# $NetBSD: Makefile,v 1.8 2023/10/24 22:08:18 wiz Exp $
#

DISTNAME=	fstl-0.10.0
PKGREVISION=	6
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
