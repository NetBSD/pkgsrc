# $NetBSD: Makefile,v 1.204 2018/11/14 22:21:27 kleink Exp $

DISTNAME=	wine-1.6.2
PKGREVISION=	21
CATEGORIES=	emulators
MASTER_SITES=	http://ibiblio.org/pub/linux/system/emulators/wine/
MASTER_SITES+=	${MASTER_SITE_SOURCEFORGE:=wine/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.winehq.org/
COMMENT=	Free implementation of Windows on Unix
LICENSE=	gnu-lgpl-v2.1

BUILD_DEPENDS+=	fontforge-[0-9]*:../../fonts/fontforge

ONLY_FOR_PLATFORM+=	*-*-i386 #*-*-x86_64

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c c99
USE_LIBTOOL=		yes
USE_NCURSES=		yes
USE_TOOLS+=		bison flex gmake mktemp msgfmt
FLEX_REQD=		2.5.33
GNU_CONFIGURE=		yes
UNLIMIT_RESOURCES=	datasize

REPLACE_PERL+=		tools/winemaker tools/winedump/function_grep.pl

# The Wine configure script has problems locating the libraries in the
# buildlink directory, so prepend all of the LDFLAGS necessary to link
# against the libraries.
CONFIGURE_ENV+=		X_LIBS=${LDFLAGS:M*:Q}
CONFIGURE_ENV+=		CFLAGS=${CFLAGS:M*:Q}\ -DDEVOSSAUDIO="\"${DEVOSSAUDIO}\""
CONFIGURE_ENV+=		LDD=${LDD:Q}
LIBS+=			${LDFLAGS}

# If we're doing a 32-bit build, make sure that the appropriate multilib
# options are passed through as these values are used with winegcc
# (which wrapper doesn't handle).
.include "../../mk/bsd.prefs.mk"
.if ${MACHINE_ARCH} == "i386"
CONFIGURE_ENV+=		ac_cv_prog_CC=${CC:Q}\ -m32
CONFIGURE_ENV+=		ac_cv_prog_CXX=${CXX:Q}\ -m32
CONFIGURE_ENV+=		ac_cv_prog_AS=${AS:Q}\ --32
CONFIGURE_ENV+=		ac_cv_prog_LD=${LD:Q}\ -m\ elf_i386
.endif
# Needs GCC >= 4.4
.if ${MACHINE_ARCH} == "x86_64"
CONFIGURE_ARGS+=	--disable-win16
CONFIGURE_ARGS+=	--enable-win64
.endif

.if ${OPSYS} == "NetBSD"
# gethostbyname_r is in libc, but has a different calling convention
CONFIGURE_ARGS+=	wine_cv_linux_gethostbyname_r_6=no
.endif

.include "options.mk"

.include "../../devel/ncurses/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../graphics/giflib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
