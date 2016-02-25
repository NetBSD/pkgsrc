# $NetBSD: Makefile,v 1.14 2016/02/25 15:35:31 jperkin Exp $

DISTNAME=	ttyrec-1.0.8
CATEGORIES=	misc
MASTER_SITES=	http://0xcc.net/ttyrec/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://0xcc.net/ttyrec/
COMMENT=	Tty recorder
LICENSE=	original-bsd

CFLAGS.SunOS+=	-DSVR4

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttyplay ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ttyrec ${DESTDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ttytime ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/ttyplay.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/ttyrec.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_MAN} ${WRKSRC}/ttytime.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
