# $NetBSD: Makefile,v 1.4 2003/07/17 22:54:20 grant Exp $
#

DISTNAME=	html2text-1.2.2
CATEGORIES=	textproc
MASTER_SITES=	http://www.gmrs.de/

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gmrs.de/html2text.html
COMMENT=	Advanced HTML-to-text converter

HAS_CONFIGURE=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/html2text ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/html2text.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/html2textrc.4 ${PREFIX}/man/man5/html2textrc.5

.include "../../mk/bsd.pkg.mk"
