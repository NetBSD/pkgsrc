# $NetBSD: Makefile,v 1.57 2003/12/25 16:46:00 fredb Exp $
#

DISTNAME=	Wine-20031212
PKGNAME=	${DISTNAME:S/W/w/}
WRKSRC= 	${WRKDIR}/${DISTNAME:S/W/w/}
CATEGORIES=	emulators
MASTER_SITES=	http://www.ibiblio.org/Linux/ALPHA/wine/development/ \
		${MASTER_SITE_SOURCEFORGE:=wine/} \
		${MASTER_SITE_SUNSITE:=ALPHA/wine/development/}

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.winehq.com/
COMMENT=	Free implementation of Windows on Unix (still alpha)

BUILD_DEPENDS+=	bison-[0-9]*:../../devel/bison

YACC=		${PREFIX}/bin/bison -y

CONFLICTS=	rewind-[0-9]*

ONLY_FOR_PLATFORM=	NetBSD-1.5Z*-i386 NetBSD-1.[6-9]*-i386 NetBSD-2*
ONLY_FOR_PLATFORM+=	FreeBSD*-i386 Linux*-i386 Solaris*-i386

BUILDLINK_DEPENDS.freetype2=	freetype>=2.1.4

USE_BUILDLINK2=		YES
USE_X11=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-curses #--disable-debug --disable-trace
CONFIGURE_ENV+=		ac_cv_path_ARTSCCONFIG=${TRUE}
CONFIGURE_ENV+=		ac_cv_prog_sane_devel=no

REPLACE_PERL=		tools/winemaker tools/winedump/function_grep.pl

# The Wine configure script has problems locating the libraries in the
# buildlink directory, so prepend all of the LDFLAGS necessary to link
# against the libraries.
#
CONFIGURE_ENV+=		X_LIBS="${LDFLAGS}"
LIBS+=			${LDFLAGS}

.include "../../mk/bsd.prefs.mk"

.if defined(USE_CUPS) && (${USE_CUPS} == YES)
.  include "../../print/cups/buildlink2.mk"
BUILD_DEFS+=		USE_CUPS
.endif

EGDIR=			${PREFIX}/share/examples/wine

post-install:
	${INSTALL_DATA_DIR} ${EGDIR}
	${INSTALL_DATA} ${WRKSRC}/winedefault.reg ${EGDIR}/winedefault.reg
	cd ${WRKSRC}/documentation/samples &&				\
	${INSTALL_DATA} config ${EGDIR}/wine.conf &&			\
	${INSTALL_DATA} generic.ppd ${EGDIR}/generic.ppd &&		\
	${INSTALL_DATA} system.ini ${EGDIR}/system.ini &&		\
	${RMDIR} ${PREFIX}/man/man3w

.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../graphics/glut/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/libungif/buildlink2.mk"
.include "../../textproc/icu/buildlink2.mk"

.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
