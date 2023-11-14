# $NetBSD: Makefile,v 1.7 2023/11/14 14:02:33 wiz Exp $

DISTNAME=	frei0r-plugins-1.8.0
PKGNAME=	${DISTNAME:S/-plugins//}
PKGREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	https://files.dyne.org/frei0r/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://frei0r.dyne.org/
COMMENT=	Collection of free and portable video plugins
LICENSE=	gnu-gpl-v2

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c c++

CMAKE_ARGS+=	-DCMAKE_BUILD_TYPE="Release"
# Not in pkgsrc yet
CMAKE_ARGS+=	-DWITHOUT_GAVL=ON
# Not compatible with latest version
CMAKE_ARGS+=	-DWITHOUT_OPENCV=ON

.include "../../graphics/cairo/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
