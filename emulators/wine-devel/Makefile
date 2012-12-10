# $NetBSD: Makefile,v 1.35 2012/12/10 12:32:40 ryoon Exp $

DISTNAME=	wine-1.3.26
PKGREVISION=	9
CATEGORIES=	emulators
MASTER_SITES=	http://ibiblio.org/pub/linux/system/emulators/wine/ \
		${MASTER_SITE_SOURCEFORGE:=wine/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.winehq.com/
COMMENT=	Free implementation of Windows on Unix
LICENSE=	gnu-lgpl-v2.1

BUILD_DEPENDS+=	fontforge-[0-9]*:../../fonts/fontforge

ONLY_FOR_PLATFORM+=	*-*-i386
#ONLY_FOR_PLATFORM+=	*-*-x86_64

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
USE_NCURSES=		yes
USE_TOOLS+=		bison flex gmake mktemp
FLEX_REQD=		2.5.33
GNU_CONFIGURE=		yes
UNLIMIT_RESOURCES=	datasize

REPLACE_PERL+=		tools/winemaker tools/winedump/function_grep.pl

# The Wine configure script has problems locating the libraries in the
# buildlink directory, so prepend all of the LDFLAGS necessary to link
# against the libraries.
#
CONFIGURE_ENV+=		X_LIBS=${LDFLAGS:M*:Q}
CONFIGURE_ENV+=		CFLAGS=${CFLAGS:M*:Q}\ -DDEVOSSAUDIO="\"${DEVOSSAUDIO}\""
CONFIGURE_ENV+=		LDD=${LDD:Q}
LIBS+=			${LDFLAGS}

# If we're doing a 32-bit build, make sure that the appropriate multilib
# options are passed through as these values are used with winegcc
# (which wrapper doesn't handle).
.include "../../mk/bsd.prefs.mk"
.if !empty(MACHINE_ARCH:Mi386)
CONFIGURE_ENV+=		ac_cv_prog_CC=${CC:Q}\ -m32
CONFIGURE_ENV+=		ac_cv_prog_CXX=${CXX:Q}\ -m32
CONFIGURE_ENV+=		ac_cv_prog_AS=${AS:Q}\ --32
CONFIGURE_ENV+=		ac_cv_prog_LD=${LD:Q}\ -m\ elf_i386
.endif
# Needs GCC >= 4.4
#.if !empty(MACHINE_ARCH:Mx86_64)
#CONFIGURE_ARGS+=	--disable-win16
#CONFIGURE_ARGS+=	--enable-win64
#.endif

.include "options.mk"

post-install:
.for tool in fnt2bdf
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/tools/${tool} \
		${DESTDIR}${PREFIX}/bin
.endfor

.include "../../devel/ncurses/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../security/gnutls/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/giflib.buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
