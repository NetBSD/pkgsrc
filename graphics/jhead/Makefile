# $NetBSD: Makefile,v 1.11 2003/04/23 06:01:29 wiz Exp $
#

DISTNAME=	jhead-2.0
CATEGORIES=	graphics
MASTER_SITES=	http://www.sentex.net/~mwandel/jhead/

MAINTAINER=	veego@netbsd.org
HOMEPAGE=	http://www.sentex.net/~mwandel/jhead/
COMMENT=	Extract EXIF header from JPEG image

LIBS=		-lm -L${BUILDLINK_PREFIX.jpeg}/lib -Wl,${RPATH_FLAG}${BUILDLINK_PREFIX.jpeg}/lib -ljpeg

USE_BUILDLINK2=	yes

do-build:
	cd ${WRKSRC} && \
		 ${CC} ${CFLAGS} -o jhead jhead.c exif.c jpgfile.c ${LIBS}
	${GZIP_CMD} -d ${WRKSRC}/jhead.1.gz

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/jhead
	${INSTALL_PROGRAM} ${WRKSRC}/jhead ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/jhead.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/usage.html ${PREFIX}/share/doc/html/jhead

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
