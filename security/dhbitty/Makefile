# $NetBSD: Makefile,v 1.1.1.1 2012/08/11 17:43:46 agc Exp $

DISTNAME=		dhbitty.c
PKGNAME=		dhbitty-20120806
CATEGORIES=		security
MASTER_SITES=		http://cipherdev.org/rnd/
EXTRACT_SUFX=		#empty

MAINTAINER=		agc@NetBSD.org
COMMENT=		Small public key ECDH encryption/decryption program
HOMEPAGE=		http://cipherdev.org/dhbitty.html
LICENSE=		public-domain

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

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
