# $NetBSD: Makefile,v 1.91 2005/10/10 08:32:23 adam Exp $

DISTNAME=	Wine-20050930
PKGNAME=	${DISTNAME:S/W/w/}
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
USE_LIBTOOL=		yes
USE_NCURSES=		yes
USE_TOOLS+=		bison gmake mktemp
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-debug
CONFIGURE_ARGS+=	--disable-trace
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

.include "../../audio/esound/buildlink3.mk"
.include "../../databases/openldap/buildlink3.mk"
.include "../../devel/ncurses/buildlink3.mk"
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
