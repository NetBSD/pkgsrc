# $NetBSD: Makefile,v 1.80 2019/07/10 10:32:56 nia Exp $

DISTNAME=	openttd-1.9.1-source
PKGNAME=	${DISTNAME:S/-source//}
CATEGORIES=	games x11
MASTER_SITES=	https://proxy.binaries.openttd.org/openttd-releases/${PKGVERSION_NOREV}/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.openttd.org/
COMMENT=	Open source clone of Transport Tycoon Deluxe
LICENSE=	gnu-gpl-v2

WRKSRC=			${WRKDIR}/${PKGNAME_NOREV}
USE_LANGUAGES=		c c++0x
USE_TOOLS+=		gmake pkg-config
BUILD_DEFS+=		VARBASE
BUILD_TARGET=		bundle

HAS_CONFIGURE=		yes
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
CONFIGURE_ARGS+=	--with-iconv=${BUILDLINK_PREFIX.iconv}
CONFIGURE_ARGS+=	--with-lzo2=${BUILDLINK_PREFIX.lzo}/lib

.include "../../mk/bsd.prefs.mk"

CONFIGURE_ARGS.DragonFly+=	--os=FREEBSD

.if ${OPSYS} == "Darwin"
CONFIGURE_ARGS+=	--disable-cocoa-quickdraw
CONFIGURE_ARGS+=	--with-cocoa
CONFIGURE_ARGS+=	--without-application-bundle
CONFIGURE_ARGS+=	--without-osx-sysroot
.else
.include "../../devel/SDL/buildlink3.mk"
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
