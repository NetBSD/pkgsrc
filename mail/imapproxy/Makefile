# $NetBSD: Makefile,v 1.4 2004/04/18 05:31:35 snj Exp $
#

DISTNAME=	imapproxy-1.0
CATEGORIES=	mail
MASTER_SITES=	http://www.kuleuven.net/projects/imapproxy/download/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.kuleuven.net/projects/imapproxy/
COMMENT=	Simple connection caching IMAP proxy daemon

USE_BUILDLINK3=	YES
GNU_CONFIGURE=	YES

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/imapproxy ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/imapproxy
.for doc in BUGS COPYING ChangeLog FAQ INSTALL README THANKS TODO
	${INSTALL_DATA} ${WRKSRC}/${doc} ${PREFIX}/share/doc/imapproxy
.endfor

.include "../../mk/bsd.pkg.mk"
