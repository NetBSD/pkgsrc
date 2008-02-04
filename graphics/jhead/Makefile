# $NetBSD: Makefile,v 1.22 2008/02/04 14:42:14 wiz Exp $
#

DISTNAME=	jhead-2.4
CATEGORIES=	graphics
MASTER_SITES=	http://www.sentex.net/~mwandel/jhead/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sentex.net/~mwandel/jhead/
COMMENT=	Extract EXIF header from JPEG image

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_TOOLS+=	gunzip
MAKE_FILE=	makefile

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/html/jhead

post-extract:
	${GUNZIP_CMD} ${WRKSRC}/jhead.1.gz

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/html/jhead
	${INSTALL_PROGRAM} ${WRKSRC}/jhead ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/jhead.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/usage.html ${PREFIX}/share/doc/html/jhead

.include "../../mk/bsd.pkg.mk"
