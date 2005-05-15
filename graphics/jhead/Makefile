# $NetBSD: Makefile,v 1.17 2005/05/15 22:02:27 jlam Exp $
#

DISTNAME=	jhead-2.3
CATEGORIES=	graphics
MASTER_SITES=	http://www.sentex.net/~mwandel/jhead/

MAINTAINER=	veego@NetBSD.org
HOMEPAGE=	http://www.sentex.net/~mwandel/jhead/
COMMENT=	Extract EXIF header from JPEG image

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKGSRC_USE_TOOLS+=	gunzip

INSTALLATION_DIRS=	bin man/man1 share/doc/html/jhead

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o jhead \
		jhead.c exif.c jpgfile.c makernote.c -lm
	${GUNZIP_CMD} ${WRKSRC}/jhead.1.gz

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/jhead
	${INSTALL_PROGRAM} ${WRKSRC}/jhead ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/jhead.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/usage.html ${PREFIX}/share/doc/html/jhead

.include "../../mk/bsd.pkg.mk"
