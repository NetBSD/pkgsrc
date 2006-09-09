# $NetBSD: Makefile,v 1.20 2006/09/09 02:42:01 obache Exp $
#

DISTNAME=	jhead-2.4
CATEGORIES=	graphics
MASTER_SITES=	http://www.sentex.net/~mwandel/jhead/

MAINTAINER=	veego@NetBSD.org
HOMEPAGE=	http://www.sentex.net/~mwandel/jhead/
COMMENT=	Extract EXIF header from JPEG image

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	gunzip
MAKE_FILE=	makefile

INSTALLATION_DIRS=	bin man/man1 share/doc/html/jhead

post-extract:
	${GUNZIP_CMD} ${WRKSRC}/jhead.1.gz

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/jhead
	${INSTALL_PROGRAM} ${WRKSRC}/jhead ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/jhead.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/usage.html ${PREFIX}/share/doc/html/jhead

.include "../../mk/bsd.pkg.mk"
