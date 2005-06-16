# $NetBSD: Makefile,v 1.6 2005/06/16 06:58:02 jlam Exp $
#

DISTNAME=	imapproxy-1.0
CATEGORIES=	mail
MASTER_SITES=	http://www.kuleuven.net/projects/imapproxy/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.kuleuven.net/projects/imapproxy/
COMMENT=	Simple connection caching IMAP proxy daemon

GNU_CONFIGURE=	YES

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/imapproxy ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/imapproxy
.for doc in BUGS COPYING ChangeLog FAQ INSTALL README THANKS TODO
	${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/imapproxy
.endfor

.include "../../mk/bsd.pkg.mk"
