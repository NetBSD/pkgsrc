# $NetBSD: Makefile,v 1.1 1998/08/28 12:53:03 garbled Exp $

DISTNAME=	linuxdoom-1.10
PKGNAME=	xdoom-1.10
CATEGORIES=	games x11
MASTER_SITES=	ftp://ftp.idsoftware.com/idstuff/source/
MASTER_SITES+=	ftp://ftp.idsoftware.com/idstuff/doom/
DISTFILES=	doomsrc.zip doom-1.8.wad.gz

MAINTAINER=	root@garbled.net
HOMEPAGE=	http://www.idsoftware.com/archives/doomarc.html

BUILD_DEPENDS=	unzip:../../archivers/unzip

EXTRACT_CMD=	unzip
EXTRACT_BEFORE_ARGS=	-qo
EXTRACT_ONLY=	doomsrc.zip
USE_X11=	yes
USE_GMAKE=	yes

post-extract:
	(cd ${WRKDIR}; tar xzf linuxdoom-1.10.src.tgz)

post-patch:
	@${MV} ${WRKSRC}/i_sound.c foo
	@${SED} -e 's@XXXPREFIXXXX@${PREFIX}@' <foo> ${WRKSRC}/i_sound.c
	@${MV} ${WRKSRC}/d_main.c foo
	@${SED} -e 's@XXXPREFIXXXX@${PREFIX}@' <foo> ${WRKSRC}/d_main.c
	@${RM} -f foo

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/linux/linuxxdoom ${PREFIX}/bin/xdoom
	${MKDIR} ${PREFIX}/share/doom
	${GUNZIP_CMD} -c ${DISTDIR}/doom-1.8.wad.gz > ${PREFIX}/share/doom/doom1.wad

.include "../../mk/bsd.pkg.mk"
