# $NetBSD: Makefile,v 1.12 2001/02/16 15:11:01 wiz Exp $

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

BUILD_DEPENDS=	unzip:../../archivers/unzip

LICENSE=	shareware

EXTRACT_ONLY=	doomsrc.zip
EXTRACT_CMD=	unzip -qo ${DISTDIR}/${EXTRACT_ONLY}
USE_X11BASE=	yes
USE_GMAKE=	yes

post-extract:
	(cd ${WRKDIR}; ${GTAR} xzf linuxdoom-1.10.src.tgz)
	(cd ${WRKDIR}; ${GTAR} xzf sndserv.tgz)

do-build:
	cd ${WRKSRC}/${DISTNAME} ; ${GMAKE} X11BASE=${X11BASE}
	cd ${WRKSRC}/sndserv ; ${GMAKE} X11BASE=${X11BASE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME}/linux/linuxxdoom ${PREFIX}/bin/xdoom
	${INSTALL_PROGRAM} ${WRKSRC}/sndserv/linux/sndserver ${PREFIX}/bin/sndserver
	${MKDIR} ${PREFIX}/share/doom
	${GUNZIP_CMD} -c ${DISTDIR}/doom-1.8.wad.gz > ${PREFIX}/share/doom/doom1.wad

.include "../../mk/bsd.pkg.mk"
