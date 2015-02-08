# $NetBSD: Makefile,v 1.33 2015/02/08 16:12:22 wiz Exp $

DISTNAME=	jhead-3.00
CATEGORIES=	graphics
MASTER_SITES=	http://www.sentex.net/~mwandel/jhead/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.sentex.net/~mwandel/jhead/
COMMENT=	Extract EXIF header from JPEG image
LICENSE=	public-domain

MAKE_FILE=	makefile

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/html/jhead

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jhead ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/jhead.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/usage.html \
		${DESTDIR}${PREFIX}/share/doc/html/jhead

.include "../../mk/bsd.pkg.mk"
