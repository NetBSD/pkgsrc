# $NetBSD: Makefile,v 1.2 2024/06/20 20:23:23 charlotte Exp $

PKGNAME=	openclonk-8.1
DISTNAME=	openclonk-${PKGVERSION_NOREV}-src
CATEGORIES=	games
MASTER_SITES=	http://www.openclonk.org/builds/release/${VERSION}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	http://www.openclonk.org/
COMMENT=	Open source successor of the Clonk gaming series
LICENSE=	isc

WRKSRC=		${WRKDIR}/openclonk-release-${PKGVERSION_NOREV}-src
EXTRACT_USING=	gtar
USE_LANGUAGES=	c c++
USE_TOOLS+=	pkg-config
GCC_REQD+=	4.9

.include "../../devel/cmake/build.mk"
.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../audio/freealut/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/readline/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../net/miniupnpc/buildlink3.mk"
.include "../../textproc/tinyxml/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../x11/gtksourceview3/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
