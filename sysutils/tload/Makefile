# $NetBSD: Makefile,v 1.8 2007/01/07 09:14:13 rillig Exp $
#

DISTNAME=	procps-2.0.6
PKGNAME=	tload-2.0.6
PKGREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://people.redhat.com/johnsonm/procps/

MAINTAINER=	hubertf@NetBSD.org
COMMENT=	Terminal version of xload

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

do-build:
	cd ${WRKSRC} ; \
	${CC} ${CFLAGS} tload.c -o tload

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tload ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tload.1 ${PREFIX}/${PKGMANDIR}/man1

.include "../../mk/bsd.pkg.mk"
