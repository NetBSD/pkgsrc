# $NetBSD: Makefile,v 1.51 2003/09/23 05:34:35 adam Exp $

DISTNAME=		Wine-20030911
PKGNAME=		${DISTNAME:S/W/w/}
WRKSRC= 		${WRKDIR}/${DISTNAME:tl}
CATEGORIES=		emulators
MASTER_SITES=		http://www.ibiblio.org/Linux/ALPHA/wine/development/ \
			${MASTER_SITE_SOURCEFORGE:=wine/} \
			${MASTER_SITE_SUNSITE:=ALPHA/wine/development/}

MAINTAINER=		adam@NetBSD.org
HOMEPAGE=		http://www.winehq.com/
COMMENT=		Free implementation of Windows on Unix (still alpha)

CONFLICTS=		rewind-[0-9]*

ONLY_FOR_PLATFORM=	NetBSD-1.5Z*-i386 NetBSD-1.[6-9]*-i386

USE_BUILDLINK2=		YES
USE_X11=		YES
USE_GMAKE=		YES
USE_LIBTOOL=		YES
BUILD_DEPENDS+=		bison-[0-9]*:../../devel/bison
YACC=			${PREFIX}/bin/bison -y

GNU_CONFIGURE=		YES
CONFIGURE_ARGS+=	--without-curses #--without-opengl
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
	${INSTALL_DATA} win.ini ${EGDIR}/win.ini
	${RMDIR} ${PREFIX}/man/man3w

.include "../../graphics/MesaLib/buildlink2.mk"
.include "../../graphics/freetype2/buildlink2.mk"
.include "../../graphics/glu/buildlink2.mk"
.include "../../graphics/jpeg/buildlink2.mk"
.include "../../graphics/libungif/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
