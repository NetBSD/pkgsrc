# $NetBSD: Makefile,v 1.39 2006/09/08 07:49:36 joerg Exp $

DISTNAME=	linuxdoom-1.10
PKGNAME=	xdoom-1.10
PKGREVISION=	3
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.idsoftware.com/idstuff/source/
MASTER_SITES+=	ftp://ftp.idsoftware.com/idstuff/doom/
DISTFILES=	doomsrc.zip doom-1.8.wad.gz

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.idsoftware.com/archives/doomarc.html
COMMENT=	3D shoot-em-up for 8-bit X11 displays

LICENSE=	xdoom-license

EXTRACT_ONLY=		doomsrc.zip
EXTRACT_OPTX_ZIP=	-qo

WRKSRC=		${WRKDIR}
USE_X11BASE=	yes
USE_TOOLS+=	gmake gunzip tar unzip
MAKE_ENV+=	X11BASE=${X11BASE:Q} INSTALL_PREFIX=${PREFIX:Q}

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "Linux"
CFLAGS+=	-DLINUX
.endif

.include "../../mk/endian.mk"

.if ${MACHINE_ENDIAN} == "big"
CFLAGS+=	-D__BIG_ENDIAN__=1
.endif

INSTALLATION_DIRS=	bin

.include "../../mk/oss.buildlink3.mk"
.include "../../mk/x11.buildlink3.mk"

post-extract:
	(cd ${WRKDIR}; ${TAR} xzf linuxdoom-1.10.src.tgz)
	(cd ${WRKDIR}; ${TAR} xzf sndserv.tgz)

do-build:
	cd ${WRKSRC}/${DISTNAME} && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS}
	cd ${WRKSRC}/sndserv && ${SETENV} ${MAKE_ENV} ${MAKE_PROGRAM} ${MAKE_FLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME}/linux/linuxxdoom ${PREFIX}/bin/xdoom
	${INSTALL_PROGRAM} ${WRKSRC}/sndserv/linux/sndserver ${PREFIX}/bin/sndserver
	${INSTALL_DATA_DIR} ${PREFIX}/share/doom
	${GUNZIP_CMD} -c ${DISTDIR}/doom-1.8.wad.gz > ${PREFIX}/share/doom/doom1.wad

.include "../../mk/bsd.pkg.mk"
