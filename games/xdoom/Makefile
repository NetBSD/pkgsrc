# $NetBSD: Makefile,v 1.4 1998/09/06 16:44:53 hubertf Exp $

DISTNAME=	linuxdoom-1.10
PKGNAME=	xdoom-1.10
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.idsoftware.com/idstuff/source/
MASTER_SITES+=	ftp://ftp.idsoftware.com/idstuff/doom/
DISTFILES=	doomsrc.zip doom-1.8.wad.gz

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.idsoftware.com/archives/doomarc.html

LICENSE=	shareware

BUILD_DEPENDS=	unzip:../../archivers/unzip

WRKSRC=		${WRKDIR}
EXTRACT_CMD=	unzip
EXTRACT_BEFORE_ARGS=	-qo
EXTRACT_ONLY=	doomsrc.zip
USE_X11=	yes
USE_GMAKE=	yes

post-extract:
	(cd ${WRKDIR}; tar xzf linuxdoom-1.10.src.tgz)
	(cd ${WRKDIR}; tar xzf sndserv.tgz)

post-patch:
	@${MV} ${WRKSRC}/${DISTNAME}/i_sound.c foo
	@${SED} -e 's@XXXPREFIXXXX@${PREFIX}@' <foo> ${WRKSRC}/${DISTNAME}/i_sound.c
	@${MV} ${WRKSRC}/${DISTNAME}/d_main.c foo
	@${SED} -e 's@XXXPREFIXXXX@${PREFIX}@' <foo> ${WRKSRC}/${DISTNAME}/d_main.c
	@${RM} -f foo

do-build:
	cd ${WRKSRC}/${DISTNAME} ; ${GMAKE} X11BASE=${X11BASE}
	cd ${WRKSRC}/sndserv ; ${GMAKE} X11BASE=${X11BASE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME}/linux/linuxxdoom ${PREFIX}/bin/xdoom
	${INSTALL_PROGRAM} ${WRKSRC}/sndserv/linux/sndserver ${PREFIX}/bin/sndserver
	${MKDIR} ${PREFIX}/share/doom
	${GUNZIP_CMD} -c ${DISTDIR}/doom-1.8.wad.gz > ${PREFIX}/share/doom/doom1.wad

.include "../../mk/bsd.pkg.mk"
