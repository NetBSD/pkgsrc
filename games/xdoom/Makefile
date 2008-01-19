# $NetBSD: Makefile,v 1.42 2008/01/19 09:16:23 wiz Exp $

DISTNAME=	linuxdoom-1.10
PKGNAME=	xdoom-1.10
PKGREVISION=	3
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.idsoftware.com/idstuff/source/
MASTER_SITES+=	ftp://ftp.idsoftware.com/idstuff/doom/
DISTFILES=	doomsrc.zip doom-1.8.wad.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
# HOMEPAGE=	http://www.idsoftware.com/archives/doomarc.html
# AWOL
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

.include "../../x11/libXext/buildlink3.mk"
.include "../../x11/xextproto/buildlink3.mk"
.include "../../mk/oss.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
