# $NetBSD: Makefile,v 1.3 2014/10/09 14:06:51 wiz Exp $

DISTNAME=		dhbitty.c
PKGNAME=		dhbitty-20120806
CATEGORIES=		security
MASTER_SITES=		http://cipherdev.org/rnd/
EXTRACT_SUFX=		#empty

MAINTAINER=		agc@NetBSD.org
COMMENT=		Small public key ECDH encryption/decryption program
HOMEPAGE=		http://cipherdev.org/dhbitty.html
LICENSE=		public-domain

WRKSRC=			${WRKDIR}

INSTALLATION_DIRS=	bin share/doc/dhbitty

do-extract:
	${MKDIR} ${WRKSRC}
	${CP} ${DISTDIR}/dhbitty.c ${WRKSRC}/dhbitty.c

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -o dhbitty dhbitty.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dhbitty ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${FILESDIR}/dhbitty.html ${DESTDIR}${PREFIX}/share/doc/dhbitty/

.include "../../mk/bsd.pkg.mk"
