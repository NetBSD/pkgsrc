# $NetBSD: Makefile,v 1.4 2000/02/05 18:36:19 wiz Exp $

DISTNAME=	q1source
PKGNAME=	quake-2.30
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.cdrom.com/pub/idgames/idstuff/source/ \
		ftp://ftp.fu-berlin.de/pub/pc/msdos/games/idgames/idstuff/source/ \
		ftp://ftp.idsoftware.com/idstuff/source/
EXTRACT_SUFX=	.zip

MAINTAINER=	tron@netbsd.org
HOMEPAGE=	http://www.idsoftware.com/

BUILD_DEPENDS+=	${UNZIP}:../../archivers/unzip
DEPENDS+=	Mesa-*:../../graphics/Mesa

ONLY_FOR_PLATFORMS=	NetBSD-1.4.[1-9]-i386
USE_GMAKE=	yes
.include "../../mk/bsd.prefs.mk"

.if (${OBJECT_FMT} == "ELF")
CFLAGS+=-DELF
.else
CFLAGS+=-DAOUT
.endif

EXTRACT_CMD=	${UNZIP} -q ${DISTDIR}/${EXTRACT_ONLY}
MAKE_ENV+=	MAINDIR=${WRKSRC}
UNZIP=		${LOCALBASE}/bin/unzip
WRKSRC=		${WRKDIR}
USE_X11BASE=	yes

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
