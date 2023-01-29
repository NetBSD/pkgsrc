# $NetBSD: Makefile,v 1.10 2023/01/29 21:16:17 ryoon Exp $

DISTNAME=	love-0.8.0-linux-src
PKGNAME=	${DISTNAME:S/-linux-src//:S/love/love08/}
PKGREVISION=	6
CATEGORIES=	games lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=love2d/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://love2d.org/
COMMENT=	Framework for making 2D games in Lua (version 0.8)
LICENSE=	zlib

WRKSRC=		${WRKDIR}/${DISTNAME:S/-linux-src//}
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes

# Avoid detecting unversioned lua in NetBSD.
SUBST_CLASSES+=		lua
SUBST_STAGE.lua=	pre-configure
SUBST_FILES.lua=	configure
SUBST_SED.lua=		-e 's,lua lua5.1,lua5.1,g'

GNU_CONFIGURE_PREFIX=		${PREFIX}/love0.8

INSTALLATION_DIRS+=	bin
post-install:
	${LN} -sf ../love0.8/bin/love ${DESTDIR}${PREFIX}/bin/love0.8

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
BUILDLINK_API_DEPENDS.physfs+=	physfs>=2.0
.include "../../devel/physfs/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../lang/lua51/buildlink3.mk"
.include "../../devel/devIL/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../audio/libmodplug/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
