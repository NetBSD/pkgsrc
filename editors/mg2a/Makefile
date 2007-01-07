# $NetBSD: Makefile,v 1.8 2007/01/07 00:18:43 rillig Exp $

DISTNAME=	mg2a
PKGNAME=	mg2a-1.11
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.wustl.edu/languages/c/unix-c/editors/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	tron@NetBSD.org
COMMENT=	Small, fast, public domain EMACS style editor

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man1

post-extract:
	cd ${WRKSRC} && ${CP} sys/bsd/Makefile .

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/mg ${PREFIX}/bin/mg
	${INSTALL_MAN} ${WRKSRC}/mg.1 ${PREFIX}/${PKGMANDIR}/man1
	${INSTALL_DATA} ${WRKSRC}/mg.rc ${PREFIX}/bin/mg.rc

.include "../../mk/bsd.pkg.mk"
