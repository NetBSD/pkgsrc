# $NetBSD: Makefile,v 1.87.2.1 2005/08/13 05:32:37 snj Exp $

DISTNAME=	Wine-20050524
PKGNAME=	${DISTNAME:S/W/w/}
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=wine/} \
		http://www.ibiblio.org/pub/Linux/ALPHA/wine/development/ \
		${MASTER_SITE_SUNSITE:=ALPHA/wine/development/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.winehq.com/
COMMENT=	Free implementation of Windows on Unix (still alpha)

BUILD_DEPENDS+=	fontforge-[0-9]*:../../fonts/fontforge

CONFLICTS=	rewind-[0-9]*

ONLY_FOR_PLATFORM=	NetBSD-1.5Z*-i386 NetBSD-1.6*-i386 NetBSD-[2-9]*-i386
ONLY_FOR_PLATFORM+=	FreeBSD*-i386 Linux*-i386 SunOS*-i386 Darwin*-i386

WRKSRC=		 	${WRKDIR}/${DISTNAME:S/W/w/}
USE_TOOLS+=		bison gmake mktemp
USE_LIBTOOL=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--without-curses --disable-trace #--disable-debug
CONFIGURE_ENV+=		ac_cv_path_ARTSCCONFIG=${TRUE}
CONFIGURE_ENV+=		ac_cv_prog_sane_devel=no
UNLIMIT_RESOURCES=	datasize

REPLACE_PERL=		tools/winemaker tools/winedump/function_grep.pl

# The Wine configure script has problems locating the libraries in the
# buildlink directory, so prepend all of the LDFLAGS necessary to link
# against the libraries.
#
CONFIGURE_ENV+=		X_LIBS="${LDFLAGS}"
CONFIGURE_ENV+=		CFLAGS="${CFLAGS} -DDEVOSSAUDIO=\"${DEVOSSAUDIO}\""
LIBS+=			${LDFLAGS}

.include "options.mk"

EGDIR=			${PREFIX}/share/wine

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/documentation/samples/config ${EGDIR}/config
	${RMDIR} ${PREFIX}/man/man3w

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../graphics/glut/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/libungif/buildlink3.mk"

.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
