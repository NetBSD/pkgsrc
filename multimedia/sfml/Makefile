# $NetBSD: Makefile,v 1.7 2023/11/12 13:23:03 wiz Exp $

DISTNAME=	SFML-2.5.1-sources
PKGNAME=	${DISTNAME:S/-sources//:tl}
PKGREVISION=	6
CATEGORIES=	multimedia
MASTER_SITES=	http://www.sfml-dev.org/files/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.sfml-dev.org/
COMMENT=	Free multimedia C++ API
LICENSE=	zlib

USE_CMAKE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	rm

WRKSRC=		${WRKDIR}/${DISTNAME:S/-sources//}

INSTALLATION_DIRS+=	include/SFML/Audio include/SFML/Graphics
INSTALLATION_DIRS+=	include/SFML/Network/Unix include/SFML/Network/Win32
INSTALLATION_DIRS+=	include/SFML/System/Unix include/SFML/System/Win32
INSTALLATION_DIRS+=	include/SFML/Window lib

.include "options.mk"

.include "../../graphics/glu/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../audio/libsndfile/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../x11/libXrandr/buildlink3.mk"
.include "../../x11/libX11/buildlink3.mk"
.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
