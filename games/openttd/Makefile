# $NetBSD: Makefile,v 1.86 2020/03/26 14:48:36 nia Exp $

DISTNAME=	openttd-1.9.3-source
PKGNAME=	${DISTNAME:S/-source//}
PKGREVISION=	3
CATEGORIES=	games
MASTER_SITES=	https://proxy.binaries.openttd.org/openttd-releases/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.openttd.org/
COMMENT=	Open source clone of Transport Tycoon Deluxe
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}/${PKGNAME_NOREV}
HAS_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pkg-config
BUILD_DEFS+=	VARBASE
BUILD_TARGET=	bundle

# C++11
GCC_REQD+=	4.8

BUILDLINK_TRANSFORM+=	opt:-std=c++11:-std=gnu++11 # alloca

CONFIGURE_ARGS+=	--os=UNIX
CONFIGURE_ARGS+=	--prefix-dir=${PREFIX}
CONFIGURE_ARGS+=	--binary-dir=bin
CONFIGURE_ARGS+=	--data-dir=share/openttd
CONFIGURE_ARGS+=	--doc-dir=share/doc/openttd
CONFIGURE_ARGS+=	--icon-theme-dir=share/icons/hicolor
CONFIGURE_ARGS+=	--install-dir=${DESTDIR}
CONFIGURE_ARGS+=	--man-dir=${PKGMANDIR}/man6
CONFIGURE_ARGS+=	--menu-dir=share/applications
CONFIGURE_ARGS+=	--personal-dir=.openttd
CONFIGURE_ARGS+=	--shared-dir=${VARBASE}/games/openttd

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--disable-cocoa-quickdraw
CONFIGURE_ARGS+=	--with-cocoa
CONFIGURE_ARGS+=	--without-application-bundle
CONFIGURE_ARGS+=	--without-osx-sysroot
.else
.include "../../devel/SDL/buildlink3.mk"
.include "../../x11/libxdg-basedir/buildlink3.mk"
.endif

.include "../../archivers/lzo/buildlink3.mk"
.include "../../archivers/xz/buildlink3.mk"
.include "../../audio/fluidsynth/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
