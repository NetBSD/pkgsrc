# $NetBSD: Makefile,v 1.1.1.1 1999/12/24 00:44:38 hubertf Exp $
#

DISTNAME=	procps-2.0.6
PKGNAME=	tload-2.0.6
CATEGORIES=	sysutils
MASTER_SITES=	ftp://people.redhat.com/johnsonm/procps/

MAINTAINER=	hubertf@netbsd.org

do-build:
	cd ${WRKSRC} ; \
	${CC} ${CFRLAGS} tload.c -o tload

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tload ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tload.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
