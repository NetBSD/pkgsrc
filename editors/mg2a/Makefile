# $NetBSD: Makefile,v 1.3 2000/07/10 18:26:52 tron Exp $

DISTNAME=       mg2a
PKGNAME=	mg2a-1.11
CATEGORIES=	editors
MASTER_SITES=   ftp://ftp.wustl.edu/languages/c/unix-c/editors/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=	tron@netbsd.org

post-extract:
	cd ${WRKSRC} ; ${CP} sys/bsd/Makefile .

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mg ${PREFIX}/bin/mg
	${INSTALL_MAN} ${WRKSRC}/mg.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/mg.rc ${PREFIX}/bin/mg.rc

.include "../../mk/bsd.pkg.mk"
