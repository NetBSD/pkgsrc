# $NetBSD: Makefile,v 1.3 2001/10/14 07:14:24 veego Exp $
#

DISTNAME=	jhead
PKGNAME=	jhead-1.4
CATEGORIES=	graphics
MASTER_SITES=	http://www.sentex.net/~mwandel/jhead/
EXTRACT_SUFX=	.zip

MAINTAINER=	veego@netbsd.org
HOMEPAGE=	http://www.sentex.net/~mwandel/jhead/
COMMENT=	Extract EXIF header from JPEG image

DIST_SUBDIR=	${PKGNAME}
WRKSRC=		${WRKDIR}

LIBS=		-lm

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${LIBS} -o jhead jhead.c exif.c

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/jhead
	${INSTALL_PROGRAM} ${WRKSRC}/jhead ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/usage.html ${PREFIX}/share/doc/html/jhead

.include "../../mk/bsd.pkg.mk"
