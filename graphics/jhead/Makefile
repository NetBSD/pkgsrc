# $NetBSD: Makefile,v 1.6 2002/08/04 21:54:50 jdolecek Exp $
#

DISTNAME=	jhead-1.8
CATEGORIES=	graphics
MASTER_SITES=	http://www.sentex.net/~mwandel/jhead/

MAINTAINER=	veego@netbsd.org
HOMEPAGE=	http://www.sentex.net/~mwandel/jhead/
COMMENT=	Extract EXIF header from JPEG image

LIBS=		-lm -L${LOCALBASE}/lib -ljpeg

do-build:
	cd ${WRKSRC} && \
		 ${CC} ${CFLAGS} -o jhead jhead.c exif.c jpgfile.c ${LIBS}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/jhead
	${INSTALL_PROGRAM} ${WRKSRC}/jhead ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/usage.html ${PREFIX}/share/doc/html/jhead

.include "../../graphics/jpeg/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
