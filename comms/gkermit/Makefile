# $NetBSD: Makefile,v 1.31 2024/08/05 07:50:48 tnn Exp $

DISTNAME=	gku201
PKGNAME=	gkermit-2.01
CATEGORIES=	comms
MASTER_SITES=	https://www.kermitproject.org/ftp/kermit/archives/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.kermitproject.org/gkermit.html
COMMENT=	Minimal implementation of the ``kermit'' protocol (GPL'd)
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

WRKSRC=		${WRKDIR}
BUILD_TARGET=	posix
MAKE_FILE=	makefile
MAKE_ENV+=	KFLAGS=${CFLAGS:M*:Q}

.include "../../mk/bsd.prefs.mk"

CFLAGS+=	-DERRNO_H -DNEEDUNISTD

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1 share/doc/gkermit

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gkermit ${DESTDIR}${PREFIX}/bin/gkermit
	${INSTALL_MAN} ${WRKSRC}/gkermit.nr \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man1/gkermit.1
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/gkermit

.include "../../mk/bsd.pkg.mk"
