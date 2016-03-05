# $NetBSD: Makefile,v 1.56 2016/03/05 11:28:29 jperkin Exp $

DISTNAME=	wine-1.7.36
PKGREVISION=	7
CATEGORIES=	emulators
MASTER_SITES=	http://ibiblio.org/pub/linux/system/emulators/wine/ \
		${MASTER_SITE_SOURCEFORGE:=wine/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.winehq.org/
COMMENT=	Free implementation of Windows on Unix
LICENSE=	gnu-lgpl-v2.1

BUILD_DEPENDS+=	fontforge-[0-9]*:../../fonts/fontforge

ONLY_FOR_PLATFORM+=	*-*-i386 *-*-x86_64

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
USE_NCURSES=		yes
USE_TOOLS+=		bison flex gmake mktemp msgfmt
FLEX_REQD=		2.5.33
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-tests
UNLIMIT_RESOURCES=	datasize

REPLACE_PERL+=		tools/winemaker tools/winedump/function_grep.pl

# The Wine configure script has problems locating the libraries in the
# buildlink directory, so prepend all of the LDFLAGS necessary to link
# against the libraries.
CONFIGURE_ENV+=		X_LIBS=${LDFLAGS:M*:Q}
CONFIGURE_ENV+=		CFLAGS=${CFLAGS:M*:Q}\ -DDEVOSSAUDIO="\"${DEVOSSAUDIO}\""
CONFIGURE_ENV+=		LDD=${LDD:Q}
LIBS+=			${LDFLAGS}

PLIST_VARS+=		oss wine16 wine32 wine64
# If we're doing a 32-bit build, make sure that the appropriate multilib
# options are passed through as these values are used with winegcc
# (which wrapper doesn't handle).
# XXX seems not needed anymore; to be removed on next update
.include "../../mk/bsd.prefs.mk"
.if !empty(MACHINE_ARCH:Mi386)
#CONFIGURE_ENV+=		ac_cv_prog_CC=${CC:Q}\ -m32
#CONFIGURE_ENV+=		ac_cv_prog_CXX=${CXX:Q}\ -m32
#CONFIGURE_ENV+=		ac_cv_prog_AS=${AS:Q}\ --32
#CONFIGURE_ENV+=		ac_cv_prog_LD=${LD:Q}\ -m\ elf_i386
PLIST.wine16=		yes
PLIST.wine32=		yes
.endif
# Needs GCC >= 4.4; Experimental
.if !empty(MACHINE_ARCH:Mx86_64)
CONFIGURE_ARGS+=	--enable-win64
PLIST.wine64=		yes
.endif

.if ${OPSYS} != "Darwin"
PLIST.oss=		yes
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.endif

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
