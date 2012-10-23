# $NetBSD: Makefile,v 1.48 2012/10/23 10:24:04 wiz Exp $

DISTNAME=	q1source
PKGNAME=	quake-2.30
PKGREVISION=	5
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.fu-berlin.de/pc/msdos/games/idgames/idstuff/source/ \
		ftp://ftp.idsoftware.com/idstuff/source/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.idsoftware.com/
COMMENT=	Legendary first person shoot'em up game

DEPENDS+=	quakedata-[0-9]*:../../games/quakedata

ONLY_FOR_PLATFORM=	*-*-i386

WRKSRC=		${WRKDIR}
USE_TOOLS+=	gmake
MAKE_ENV+=	MAINDIR=${WRKSRC:Q}


MAKE_ENV+=	MESA_DIR=${BUILDLINK_PREFIX.Mesa}
MAKE_ENV+=	X11BASE=${X11BASE:Q}

LDFLAGS+=	${LIBOSSAUDIO}

INSTALLATION_DIRS=	bin

do-configure:
	cd ${WRKSRC}/QW && ${LN} -fs Makefile.Linux ${MAKE_FILE}
	cd ${WRKSRC}/WinQuake && ${LN} -fs Makefile.linuxi386 ${MAKE_FILE}

do-build:
	( cd ${WRKSRC}/QW ; ${SETENV} ${MAKE_ENV} \
	    ${GMAKE} MAINDIR=`pwd` CFLAGS="${CFLAGS}" all)
	( cd ${WRKSRC}/WinQuake ; ${SETENV} ${MAKE_ENV} \
	    ${GMAKE} MAINDIR=`pwd` CFLAGS="${CFLAGS}" \
		WRKSRC="${WRKSRC}" all)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/QW/release_version/qwsv \
	    ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/QW/release_version/qwcl.x11 \
	    ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/QW/release_version/glqwcl.glx \
	    ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/WinQuake/release_version/bin/glquake.glx \
	    ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/WinQuake/release_version/bin/quake.x11 \
	    ${DESTDIR}${PREFIX}/bin

.include "../../graphics/MesaLib/buildlink3.mk"
.include "../../graphics/glu/buildlink3.mk"
.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/libXxf86dga/buildlink3.mk"
.include "../../x11/libXxf86vm/buildlink3.mk"
.include "../../x11/xf86dgaproto/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
