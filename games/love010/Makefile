# $NetBSD: Makefile,v 1.24 2024/08/15 16:32:12 bsiegert Exp $

DISTNAME=	love-0.10.2-linux-src
PKGNAME=	${DISTNAME:S/-linux-src//:S/love/love010/}
PKGREVISION=	19
CATEGORIES=	games lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=love2d/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://love2d.org/
COMMENT=	Framework for making 2D games in Lua (version 0.10)
LICENSE=	zlib

WRKSRC=		${WRKDIR}/${DISTNAME:S/-linux-src//}
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes

GNU_CONFIGURE_PREFIX=		${PREFIX}/love0.10
GNU_CONFIGURE_MANDIR=		${PREFIX}/love0.10/${PKGMANDIR}/
BUILDLINK_PASSTHRU_DIRS+=	${PREFIX}/love0.10/lib
BUILDLINK_PASSTHRU_RPATHDIRS+=	${PREFIX}/love0.10/lib

SUBST_CLASSES+=		lj
.for f in auxiliar.c auxiliar.h buffer.c except.c inet.c luasocket.c	\
	mime.c options.c select.c tcp.c timeout.c udp.c unix.c
SUBST_FILES.lj+=	src/libraries/luasocket/libluasocket/${f}
.endfor
SUBST_MESSAGE.lj=	Substituting deprecated symbols.
SUBST_STAGE.lj=		pre-configure
SUBST_SED.lj=		-e 's/luaL_reg/luaL_Reg/g'
SUBST_SED.lj+=		-e 's/luaL_putchar/luaL_addchar/g'
SUBST_SED.lj+=		-e 's/luaL_typerror/luax_typerror/g'

INSTALLATION_DIRS+=	bin
post-install:
	${LN} -sf ../love0.10/bin/love ${DESTDIR}${PREFIX}/bin/love0.10

.include "options.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
BUILDLINK_API_DEPENDS.physfs+=	physfs>=2.0
.include "../../devel/physfs/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/devIL/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../audio/libmodplug/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../x11/libXcursor/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
