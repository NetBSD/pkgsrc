# $NetBSD: Makefile,v 1.1.1.1 1999/12/28 10:42:20 rh Exp $
#

DISTNAME=	html2text-1.2.1
CATEGORIES=	textproc
MASTER_SITES=	http://www.gmrs.de/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gmrs.de/html2text.html

HAS_CONFIGURE=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/html2text ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/html2text.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/html2textrc.4 ${PREFIX}/man/man5/html2textrc.5

.include "../../mk/bsd.pkg.mk"
