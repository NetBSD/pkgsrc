# $NetBSD: Makefile,v 1.75 2004/10/03 00:14:41 tv Exp $
#

DISTNAME=	Wine-20040505
PKGNAME=	${DISTNAME:S/W/w/}
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://www.ibiblio.org/pub/Linux/ALPHA/wine/development/ \
		${MASTER_SITE_SOURCEFORGE:=wine/} \
		${MASTER_SITE_SUNSITE:=ALPHA/wine/development/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.winehq.com/
COMMENT=	Free implementation of Windows on Unix (still alpha)

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison

YACC=		${PREFIX}/bin/bison -y

CONFLICTS=	rewind-[0-9]*

ONLY_FOR_PLATFORM=	NetBSD-1.5Z*-i386 NetBSD-1.6*-i386 NetBSD-[2-9]*-i386
ONLY_FOR_PLATFORM+=	FreeBSD*-i386 Linux*-i386 SunOS*-i386

WRKSRC=		 	${WRKDIR}/${DISTNAME:S/W/w/}
USE_BUILDLINK3=		YES
USE_X11=		YES
USE_GNU_TOOLS+=		make
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-curses #--disable-debug --disable-trace
CONFIGURE_ENV+=		ac_cv_path_ARTSCCONFIG=${TRUE}
CONFIGURE_ENV+=		ac_cv_prog_sane_devel=no
UNLIMIT_RESOURCES=	datasize

REPLACE_PERL=		tools/winemaker tools/winedump/function_grep.pl

# The Wine configure script has problems locating the libraries in the
# buildlink directory, so prepend all of the LDFLAGS necessary to link
# against the libraries.
#
CONFIGURE_ENV+=		X_LIBS="${LDFLAGS}"
CONFIGURE_ENV+=		CFLAGS="${CFLAGS} -DDEVOSSAUDIO=\"\\\"${DEVOSSAUDIO}\\\"\""
LIBS+=			${LDFLAGS}

.include "../../mk/bsd.prefs.mk"

.if defined(USE_CUPS) && (${USE_CUPS} == YES)
.  include "../../print/cups/buildlink3.mk"
BUILD_DEFS+=		USE_CUPS
.endif

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
.include "../../graphics/libungif/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
