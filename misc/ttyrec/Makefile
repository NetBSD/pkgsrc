# $NetBSD: Makefile,v 1.5 2003/09/22 09:57:58 wiz Exp $

DISTNAME=	ttyrec-1.0.4
CATEGORIES=	misc
MASTER_SITES=	http://namazu.org/~satoru/ttyrec/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://namazu.org/~satoru/ttyrec/
COMMENT=	ttyrec is a tty recorder

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CFLAGS+=	-DSVR4
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttyplay ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ttyrec ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ttyplay.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/ttyrec.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
