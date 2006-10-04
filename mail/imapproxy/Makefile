# $NetBSD: Makefile,v 1.8 2006/10/04 21:47:16 wiz Exp $
#

DISTNAME=	imapproxy-1.0
CATEGORIES=	mail
MASTER_SITES=	http://www.kuleuven.net/projects/imapproxy/download/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.kuleuven.net/projects/imapproxy/
# http://www.imapproxy.org/ ?
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
