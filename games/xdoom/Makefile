# $NetBSD: Makefile,v 1.26 2005/05/15 22:02:27 jlam Exp $

DISTNAME=	linuxdoom-1.10
PKGNAME=	xdoom-1.10
PKGREVISION=	2
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.idsoftware.com/idstuff/source/
MASTER_SITES+=	ftp://ftp.idsoftware.com/idstuff/doom/
DISTFILES=	doomsrc.zip doom-1.8.wad.gz

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.idsoftware.com/archives/doomarc.html
COMMENT=	3D shoot-em-up for 8-bit X11 displays

BUILD_DEPENDS=	unzip-[0-9]*:../../archivers/unzip

LICENSE=	shareware

WRKSRC=		${WRKDIR}
EXTRACT_ONLY=	doomsrc.zip
EXTRACT_CMD=	unzip -qo ${DISTDIR}/${EXTRACT_ONLY}
USE_X11BASE=	yes
USE_GNU_TOOLS+=	make
MAKE_ENV+=	X11BASE=${X11BASE} INSTALL_PREFIX=${X11PREFIX}

PKGSRC_USE_TOOLS+=	gunzip

.include "../../mk/bsd.prefs.mk"

.ifdef ${OPSYS} == "Linux"
CFLAGS+=	-DLINUX
.endif

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-D__BIG_ENDIAN__=1
.endif

.include "../../mk/ossaudio.buildlink3.mk"

post-extract:
	(cd ${WRKDIR}; ${GTAR} xzf linuxdoom-1.10.src.tgz)
	(cd ${WRKDIR}; ${GTAR} xzf sndserv.tgz)

do-build:
	cd ${WRKSRC}/${DISTNAME} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS}
	cd ${WRKSRC}/sndserv && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME}/linux/linuxxdoom ${PREFIX}/bin/xdoom
	${INSTALL_PROGRAM} ${WRKSRC}/sndserv/linux/sndserver ${PREFIX}/bin/sndserver
	${INSTALL_DATA_DIR} ${PREFIX}/share/doom
	${GUNZIP_CMD} -c ${DISTDIR}/doom-1.8.wad.gz > ${PREFIX}/share/doom/doom1.wad

.include "../../mk/bsd.pkg.mk"
