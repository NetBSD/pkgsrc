# $NetBSD: Makefile,v 1.15 2001/07/27 11:05:58 abs Exp $

DISTNAME=	linuxdoom-1.10
PKGNAME=	xdoom-1.10nb1
WRKSRC=		${WRKDIR}
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.idsoftware.com/idstuff/source/
MASTER_SITES+=	ftp://ftp.idsoftware.com/idstuff/doom/
DISTFILES=	doomsrc.zip doom-1.8.wad.gz

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.idsoftware.com/archives/doomarc.html
COMMENT=	3D shoot-em-up for 8-bit X11 displays

BUILD_DEPENDS=	unzip-*:../../archivers/unzip

LICENSE=	shareware

EXTRACT_ONLY=	doomsrc.zip
EXTRACT_CMD=	unzip -qo ${DISTDIR}/${EXTRACT_ONLY}
USE_X11BASE=	yes
USE_GMAKE=	yes
MAKE_ENV+=	X11BASE=${X11BASE} INSTALL_PREFIX=${X11PREFIX}

post-extract:
	(cd ${WRKDIR}; ${GTAR} xzf linuxdoom-1.10.src.tgz)
	(cd ${WRKDIR}; ${GTAR} xzf sndserv.tgz)

do-build:
	cd ${WRKSRC}/${DISTNAME} ; ${GMAKE}
	cd ${WRKSRC}/sndserv ; ${GMAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME}/linux/linuxxdoom ${PREFIX}/bin/xdoom
	${INSTALL_PROGRAM} ${WRKSRC}/sndserv/linux/sndserver ${PREFIX}/bin/sndserver
	${INSTALL_DATA_DIR} ${PREFIX}/share/doom
	${GUNZIP_CMD} -c ${DISTDIR}/doom-1.8.wad.gz > ${PREFIX}/share/doom/doom1.wad

.include "../../mk/bsd.pkg.mk"
