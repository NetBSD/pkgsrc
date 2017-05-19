# $NetBSD: Makefile,v 1.67 2017/05/19 13:29:03 prlw1 Exp $

DISTNAME=	wine-1.9.18
PKGREVISION=	6
CATEGORIES=	emulators
MASTER_SITES=	http://ibiblio.org/pub/linux/system/emulators/wine/
MASTER_SITES+=	${MASTER_SITE_SOURCEFORGE:=wine/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.winehq.org/
COMMENT=	Free implementation of Windows on Unix
LICENSE=	gnu-lgpl-v2.1

BUILD_DEPENDS+=	fontforge-[0-9]*:../../fonts/fontforge

ONLY_FOR_PLATFORM+=	*-*-i386 *-*-x86_64

PKG_DESTDIR_SUPPORT=	user-destdir

GCC_REQD+=		4.7

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
USE_NCURSES=		yes
USE_TOOLS+=		bison flex gmake mktemp msgfmt autoconf
FLEX_REQD=		2.5.33
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-tests
UNLIMIT_RESOURCES=	datasize

REPLACE_PERL+=		tools/winemaker/winemaker tools/winedump/function_grep.pl

# The Wine configure script has problems locating the libraries in the
# buildlink directory, so prepend all of the LDFLAGS necessary to link
# against the libraries.
CONFIGURE_ENV+=		X_LIBS=${LDFLAGS:M*:Q}
CONFIGURE_ENV+=		CFLAGS=${CFLAGS:M*:Q}\ -DDEVOSSAUDIO="\"${DEVOSSAUDIO}\""
CONFIGURE_ENV+=		LDD=${LDD:Q}
LIBS+=			${LDFLAGS}

PLIST_VARS+=		oss wine16 wine32 wine64
.include "../../mk/bsd.prefs.mk"
.if !empty(MACHINE_ARCH:Mi386)
PLIST_SRC=		PLIST.wine32
NOT_PAX_MPROTECT_SAFE+=	bin/wine
.endif

.if !empty(MACHINE_ARCH:Mx86_64)
CONFIGURE_ARGS+=	--enable-win64 --libdir=${PREFIX}/lib
NOT_PAX_MPROTECT_SAFE+=	bin/wine64
PLIST_SRC=		PLIST.wine64
.endif

# NetBSD changes
CONFIGURE_ARGS.NetBSD+=		wine_cv_linux_gethostbyname_r_6=no
CONFIGURE_ARGS.NetBSD+=		ac_cv_header_resolv_h=no

.if ${OPSYS} != "Darwin"
PLIST.oss=		yes
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.endif

pre-configure:
	cd ${WRKSRC} && autoconf

.include "options.mk"

.include "../../devel/ncurses/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
