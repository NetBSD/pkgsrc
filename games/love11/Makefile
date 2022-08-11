# $NetBSD: Makefile,v 1.10 2022/08/11 05:08:32 gutteridge Exp $

DISTNAME=	love-11.4-linux-src
PKGNAME=	${DISTNAME:S/-linux-src//:S/love/love11/}
PKGREVISION=	1
CATEGORIES=	games lua
MASTER_SITES=	${MASTER_SITE_GITHUB:=love2d/}
GITHUB_PROJECT=	love
GITHUB_RELEASE=	${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://love2d.org/
COMMENT=	Framework for making 2D games in Lua (version 11.0)
LICENSE=	zlib

WRKSRC=		${WRKDIR}/${DISTNAME:S/-linux-src//}
GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++

# checking whether gcc version is at least 4.7...
GCC_REQD+=	4.7

USE_TOOLS+=	pkg-config
USE_LIBTOOL=	yes

GNU_CONFIGURE_PREFIX=		${PREFIX}/love11
GNU_CONFIGURE_MANDIR=		${PREFIX}/love11/${PKGMANDIR}/
BUILDLINK_PASSTHRU_DIRS+=	${PREFIX}/love11/lib
BUILDLINK_PASSTHRU_RPATHDIRS+=	${PREFIX}/love11/lib

INSTALLATION_DIRS+=	bin
post-install:
	${LN} -sf ../love11/bin/love ${DESTDIR}${PREFIX}/bin/love11

.include "options.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../audio/libmodplug/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../audio/mpg123/buildlink3.mk"
.include "../../audio/openal-soft/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../multimedia/libtheora/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
