# $NetBSD: Makefile,v 1.36 2020/01/26 17:31:21 rillig Exp $

DISTNAME=	jhead-3.03
CATEGORIES=	graphics
MASTER_SITES=	http://www.sentex.net/~mwandel/jhead/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.sentex.net/~mwandel/jhead/
COMMENT=	Extract EXIF header from JPEG image
LICENSE=	public-domain

MAKE_FILE=	makefile

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/jhead

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/jhead ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/jhead.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/usage.html \
		${DESTDIR}${PREFIX}/share/doc/jhead

.include "../../mk/bsd.pkg.mk"
