# $NetBSD: Makefile,v 1.2 2001/05/30 03:03:32 kei Exp $

DISTNAME=	ttyrec-1.0.4
CATEGORIES=	misc
MASTER_SITES=	http://namazu.org/~satoru/ttyrec/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://namazu.org/~satoru/ttyrec/
COMMENT=	ttyrec is a tty recorder

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttyplay ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ttyrec ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ttyplay.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/ttyrec.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
