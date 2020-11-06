# $NetBSD: Makefile,v 1.8 2020/11/06 12:15:54 nia Exp $

DISTNAME=	love-0.9.2-linux-src
PKGNAME=	${DISTNAME:S/-linux-src//:S/love/love09/}
PKGREVISION=	4
CATEGORIES=	games lua
MASTER_SITES=	https://bitbucket.org/rude/love/downloads/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://love2d.org/
COMMENT=	Framework for making 2D games in Lua (version 0.9)
LICENSE=	zlib

WRKSRC=		${WRKDIR}/${DISTNAME:S/-linux-src//}
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes

GNU_CONFIGURE_PREFIX=		${PREFIX}/love0.9
GNU_CONFIGURE_MANDIR=		${PREFIX}/love0.9/${PKGMANDIR}/
BUILDLINK_PASSTHRU_DIRS+=	${PREFIX}/love0.9/lib
BUILDLINK_PASSTHRU_RPATHDIRS+=	${PREFIX}/love0.9/lib

.include "options.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
BUILDLINK_API_DEPENDS.physfs+=	physfs>=2.0
.include "../../devel/physfs/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/devIL/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../audio/libmodplug/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
