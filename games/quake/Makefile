# $NetBSD: Makefile,v 1.37 2005/06/16 06:57:55 jlam Exp $

DISTNAME=	q1source
PKGNAME=	quake-2.30
PKGREVISION=	4
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.fu-berlin.de/pc/msdos/games/idgames/idstuff/source/ \
		ftp://ftp.idsoftware.com/idstuff/source/
EXTRACT_SUFX=	.zip

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.idsoftware.com/
COMMENT=	Legendary first person shoot'em up game

DEPENDS+=	quakedata-[0-9]*:../../games/quakedata

ONLY_FOR_PLATFORM=	*-*-i386

WRKSRC=		${WRKDIR}
USE_TOOLS+=	gmake
MAKE_ENV+=	MAINDIR=${WRKSRC}


MAKE_ENV+=	MESA_DIR=${BUILDLINK_PREFIX.Mesa}
MAKE_ENV+=	X11BASE=${X11BASE}

LDFLAGS+=	${LIBOSSAUDIO}

INSTALLATION_DIRS=	bin

do-configure:
	cd ${WRKSRC}/qw && ${LN} -fs makefile.linux ${MAKEFILE}
	cd ${WRKSRC}/winquake && ${LN} -fs makefile.linuxi386 ${MAKEFILE}

do-build:
	( cd ${WRKSRC}/qw ; ${SETENV} ${MAKE_ENV} \
	    ${GMAKE} MAINDIR=`pwd` CFLAGS="${CFLAGS}" all)
	( cd ${WRKSRC}/winquake ; ${SETENV} ${MAKE_ENV} \
	    ${GMAKE} MAINDIR=`pwd` CFLAGS="${CFLAGS}" \
		WRKSRC="${WRKSRC}" all)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qw/release_version/qwsv \
	    ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/qw/release_version/qwcl.x11 \
	    ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/qw/release_version/glqwcl.glx \
	    ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/winquake/release_version/bin/glquake.glx \
	    ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/winquake/release_version/bin/quake.x11 \
	    ${PREFIX}/bin

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../mk/ossaudio.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
