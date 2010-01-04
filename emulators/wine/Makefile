# $NetBSD: Makefile,v 1.154 2010/01/04 15:30:08 joerg Exp $

DISTNAME=	wine-1.0.1
PKGREVISION=	3
CATEGORIES=	emulators
MASTER_SITES=	http://ibiblio.org/pub/linux/system/emulators/wine/ \
		${MASTER_SITE_SOURCEFORGE:=wine/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.winehq.com/
COMMENT=	Free implementation of Windows on Unix

BUILD_DEPENDS+=	fontforge-[0-9]*:../../fonts/fontforge

ONLY_FOR_PLATFORM=	NetBSD-1.5Z*-i386 NetBSD-1.6*-i386 NetBSD-[2-9]*-i386
ONLY_FOR_PLATFORM+=	FreeBSD-*-i386 Linux-*-i386 SunOS-*-i386 Darwin-*-i386
ONLY_FOR_PLATFORM+=	*-*-x86_64

NOT_FOR_PLATFORM+=	NetBSD-*-x86_64

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		c
USE_LIBTOOL=		yes
USE_NCURSES=		yes
USE_TOOLS+=		bison flex gmake mktemp
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

# If we're doing a 32-bit build, make sure that the appropriate
# multilib options are passed through as these values are used
# with winegcc (which wrapper doesn't handle).
.include "../../mk/bsd.prefs.mk"
.if !empty(MACHINE_ARCH:Mi386) && ${OPSYS} != "Darwin"
CONFIGURE_ENV+=		ac_cv_prog_CC=${CC}\ -m32
CONFIGURE_ENV+=		ac_cv_prog_CXX=${CXX}\ -m32
CONFIGURE_ENV+=		ac_cv_prog_AS=${AS}\ --32
CONFIGURE_ENV+=		ac_cv_prog_LD=${LD}\ -m\ elf_i386
.endif

.include "options.mk"

post-install:
.for tool in fnt2bdf
	${LIBTOOL} --mode=install ${INSTALL_PROGRAM} ${WRKSRC}/tools/${tool} \
		${DESTDIR}${PREFIX}/bin
.endfor

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/ncurses/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
