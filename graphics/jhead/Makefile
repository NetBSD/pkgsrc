# $NetBSD: Makefile,v 1.23.10.1 2008/10/23 06:53:34 rtr Exp $
#

DISTNAME=	jhead-2.84
CATEGORIES=	graphics
MASTER_SITES=	http://www.sentex.net/~mwandel/jhead/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sentex.net/~mwandel/jhead/
COMMENT=	Extract EXIF header from JPEG image

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=	gunzip
MAKE_FILE=	makefile

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/html/jhead

post-extract:
	${GUNZIP_CMD} ${WRKSRC}/jhead.1.gz

do-install:
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/html/jhead
	${INSTALL_PROGRAM} ${WRKSRC}/jhead ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/jhead.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/usage.html \
		${DESTDIR}${PREFIX}/share/doc/html/jhead

.include "../../mk/bsd.pkg.mk"
