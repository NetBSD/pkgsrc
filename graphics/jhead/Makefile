# $NetBSD: Makefile,v 1.5 2002/02/10 22:47:47 veego Exp $
#

DISTNAME=	jhead-1.6
CATEGORIES=	graphics
MASTER_SITES=	http://www.sentex.net/~mwandel/jhead/

MAINTAINER=	veego@netbsd.org
HOMEPAGE=	http://www.sentex.net/~mwandel/jhead/
COMMENT=	Extract EXIF header from JPEG image

WRKSRC=		${WRKDIR}/${DISTNAME:S/-//}

LIBS=		-lm

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${LIBS} -o jhead jhead.c exif.c

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/jhead
	${INSTALL_PROGRAM} ${WRKSRC}/jhead ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/usage.html ${PREFIX}/share/doc/html/jhead

.include "../../mk/bsd.pkg.mk"
