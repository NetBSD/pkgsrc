# $NetBSD: Makefile,v 1.4 2001/02/16 14:40:51 wiz Exp $

DISTNAME=       mg2a
PKGNAME=	mg2a-1.11
CATEGORIES=	editors
MASTER_SITES=   ftp://ftp.wustl.edu/languages/c/unix-c/editors/
EXTRACT_SUFX=   .tar.Z

MAINTAINER=	tron@netbsd.org
COMMENT=	Small, fast, public domain EMACS style editor

post-extract:
	cd ${WRKSRC} ; ${CP} sys/bsd/Makefile .

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mg ${PREFIX}/bin/mg
	${INSTALL_MAN} ${WRKSRC}/mg.1 ${PREFIX}/man/man1
	${INSTALL_DATA} ${WRKSRC}/mg.rc ${PREFIX}/bin/mg.rc

.include "../../mk/bsd.pkg.mk"
