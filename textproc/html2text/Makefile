# $NetBSD: Makefile,v 1.3 2001/02/17 17:37:25 wiz Exp $
#

DISTNAME=	html2text-1.2.2
CATEGORIES=	textproc
MASTER_SITES=	http://www.gmrs.de/

MAINTAINER=	rh@netbsd.org
HOMEPAGE=	http://www.gmrs.de/html2text.html
COMMENT=	Advanced HTML-to-text converter

HAS_CONFIGURE=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/html2text ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/html2text.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/html2textrc.4 ${PREFIX}/man/man5/html2textrc.5

.include "../../mk/bsd.pkg.mk"
