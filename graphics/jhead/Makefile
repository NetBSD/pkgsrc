# $NetBSD: Makefile,v 1.9 2003/01/09 15:28:07 mycroft Exp $
#

DISTNAME=	jhead-1.9
CATEGORIES=	graphics
MASTER_SITES=	http://www.sentex.net/~mwandel/jhead/

MAINTAINER=	veego@netbsd.org
HOMEPAGE=	http://www.sentex.net/~mwandel/jhead/
COMMENT=	Extract EXIF header from JPEG image

LIBS=		-lm -L${BUILDLINK_PREFIX.jpeg}/lib -Wl,-R${BUILDLINK_PREFIX.jpeg}/lib -ljpeg

USE_BUILDLINK2=	yes

do-build:
	cd ${WRKSRC} && \
		 ${CC} ${CFLAGS} -o jhead jhead.c exif.c jpgfile.c ${LIBS}

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/jhead
	${INSTALL_PROGRAM} ${WRKSRC}/jhead ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/usage.html ${PREFIX}/share/doc/html/jhead

.include "../../graphics/jpeg/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
