# $NetBSD: Makefile,v 1.8 2006/09/09 13:48:02 obache Exp $

DISTNAME=	ttyrec-1.0.8
CATEGORIES=	misc
MASTER_SITES=	http://0xcc.net/ttyrec/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://0xcc.net/ttyrec/
COMMENT=	ttyrec is a tty recorder

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "SunOS"
CFLAGS+=	-DSVR4
.endif

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttyplay ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ttyrec ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ttytime ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ttyplay.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/ttyrec.1 ${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/ttytime.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
