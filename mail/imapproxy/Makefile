# $NetBSD: Makefile,v 1.5 2005/04/11 21:46:20 tv Exp $
#

DISTNAME=	imapproxy-1.0
CATEGORIES=	mail
MASTER_SITES=	http://www.kuleuven.net/projects/imapproxy/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.kuleuven.net/projects/imapproxy/
COMMENT=	Simple connection caching IMAP proxy daemon

GNU_CONFIGURE=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/imapproxy ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/imapproxy
.for doc in BUGS COPYING ChangeLog FAQ INSTALL README THANKS TODO
	${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/imapproxy
.endfor

.include "../../mk/bsd.pkg.mk"
