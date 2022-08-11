# $NetBSD: Makefile,v 1.7 2022/08/11 05:08:36 gutteridge Exp $

DISTNAME=	ValyriaTear-src-with-deps-1.1.0
PKGNAME=	${DISTNAME:tl:S/-src-with-deps//1}
PKGREVISION=	4
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_GITHUB:=ValyriaTear/}
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ValyriaTear/ValyriaTear
COMMENT=	Single player medieval fantasy 2D JRPG
LICENSE=	gnu-gpl-v2 AND gnu-gpl-v3 AND cc-by-sa-v3.0

TOOL_DEPENDS+=	dos2unix-[0-9]*:../../converters/dos2unix

WRKSRC=		${WRKDIR}/ValyriaTear

USE_CMAKE=	yes
USE_TOOLS+=	pkg-config msgfmt
USE_LANGUAGES=	c c++

LDFLAGS+=	${BUILDLINK_LDADD.gettext}

post-extract:
	dos2unix ${WRKSRC}/src/utils/src/utils/ustring.cpp

.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/glew/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../lang/lua51/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
