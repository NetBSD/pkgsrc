# $NetBSD: Makefile,v 1.18 2002/06/27 20:18:41 tron Exp $

DISTNAME=	q1source
PKGNAME=	quake-2.30
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.fu-berlin.de/pc/msdos/games/idgames/idstuff/source/ \
		ftp://ftp.idsoftware.com/idstuff/source/
EXTRACT_SUFX=	.zip

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.idsoftware.com/
COMMENT=	legendary first person shoot'em up game

DEPENDS+=	quakedata-[0-9]*:../../games/quakedata

ONLY_FOR_PLATFORM=	*-*-i386

USE_GMAKE=	yes
MAKE_ENV+=	MAINDIR=${WRKSRC}

WRKSRC=		${WRKDIR}
USE_X11BASE=	yes
USE_MESA=	yes

EVAL_PREFIX+=	MESA_DIR=Mesa
MAKE_ENV+=	MESA_DIR=${MESA_DIR}
MAKE_ENV+=	X11BASE=${X11BASE}

do-configure:
	cd ${WRKSRC}/qw && ${LN} -fs makefile.linux ${MAKEFILE}
	cd ${WRKSRC}/winquake && ${LN} -fs makefile.linuxi386 ${MAKEFILE}

#pre-build:
#	cd ${WRKSRC}/winquake && \
#		${MV} common.c common.c.orig && \
#		${SED} "s@GAMENAME, basedir@GAMENAME, \"${PREFIX}/share/quake/\"@" \
#			< common.c.orig > common.c

do-build:
	( cd ${WRKSRC}/qw ; ${SETENV} ${MAKE_ENV} ${GMAKE} MAINDIR=`pwd` CFLAGS="${CFLAGS}" all)
	( cd ${WRKSRC}/winquake ; ${SETENV} ${MAKE_ENV} ${GMAKE} MAINDIR=`pwd` CFLAGS="${CFLAGS}" \
		WRKSRC="${WRKSRC}" all)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qw/release_version/qwsv ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/qw/release_version/qwcl.x11 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/qw/release_version/glqwcl.glx ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/winquake/release_version/bin/glquake.glx ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/winquake/release_version/bin/quake.x11 ${PREFIX}/bin

post-install:
	@ ${ECHO}
	@ ${ECHO} =====================================================================
	@ ${ECHO} For running quake you need data files. Look for quakesw-1.0.6.tar.gz.
	@ ${ECHO} Extract it somewhere, and start quake from the same directory, e.g.
	@ ${ECHO} by running \'quake.x11\'.
	@ ${ECHO} =====================================================================

.include "../../mk/bsd.pkg.mk"
