# $NetBSD: Makefile,v 1.10 2000/10/15 12:06:35 rh Exp $

DISTNAME=	q1source
PKGNAME=	quake-2.30
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.cdrom.com/pub/idgames/idstuff/source/ \
		ftp://ftp.fu-berlin.de/pc/msdos/games/idgames/idstuff/source/ \
		ftp://ftp.idsoftware.com/idstuff/source/
EXTRACT_SUFX=	.zip

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.idsoftware.com/

DEPENDS+=	quakedata-*:../../games/quakedata

EXTRACT_CMD=	unzip -q ${DOWNLOADED_DISTFILE}

USE_GMAKE=	yes
MAKE_ENV+=	MAINDIR=${WRKSRC}

NO_WRKSUBDIR=	yes
USE_X11BASE=	yes
USE_MESA=	yes

EVAL_PREFIX+=	MESA_DIR=Mesa
MAKE_ENV+=	MESA_DIR=${MESA_DIR}

do-configure:
	cd ${WRKSRC}/QW && ${LN} -fs Makefile.Linux ${MAKEFILE}
	cd ${WRKSRC}/WinQuake && ${LN} -fs Makefile.linuxi386 ${MAKEFILE}

#pre-build:
#	cd ${WRKSRC}/WinQuake && \
#		${MV} common.c common.c.orig && \
#		${SED} "s@GAMENAME, basedir@GAMENAME, \"${PREFIX}/share/quake/\"@" \
#			< common.c.orig > common.c

do-build:
	@( cd ${WRKSRC}/QW ; ${GMAKE} MAINDIR=`pwd` CFLAGS="${CFLAGS}" all)
	@( cd ${WRKSRC}/WinQuake ; ${GMAKE} MAINDIR=`pwd` CFLAGS="${CFLAGS}" \
		WRKSRC="${WRKSRC}" all)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/QW/release_version/qwsv ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/QW/release_version/qwcl.x11 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/QW/release_version/glqwcl.glx ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/WinQuake/release_version/bin/glquake.glx ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/WinQuake/release_version/bin/quake.x11 ${PREFIX}/bin

post-install:
	@ ${ECHO}
	@ ${ECHO} =====================================================================
	@ ${ECHO} For running quake you need data files. Look for quakesw-1.0.6.tar.gz.
	@ ${ECHO} Extract it somewhere, and start quake from the same directory, e.g.
	@ ${ECHO} by running \'quake.x11\'.
	@ ${ECHO} =====================================================================

.include "../../mk/bsd.pkg.mk"
