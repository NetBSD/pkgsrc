# $NetBSD: Makefile,v 1.4 2001/05/22 02:59:25 hubertf Exp $
#

DISTNAME=	procps-2.0.6
PKGNAME=	tload-2.0.6nb1
CATEGORIES=	sysutils
MASTER_SITES=	ftp://people.redhat.com/johnsonm/procps/

MAINTAINER=	hubertf@netbsd.org
COMMENT=	Terminal version of xload

do-build:
	cd ${WRKSRC} ; \
	${CC} ${CFLAGS} tload.c -o tload

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/tload ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/tload.1 ${PREFIX}/man/man1

.include "../../mk/bsd.pkg.mk"
