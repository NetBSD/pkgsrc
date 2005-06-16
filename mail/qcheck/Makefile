# $NetBSD: Makefile,v 1.5 2005/06/16 06:58:08 jlam Exp $
#

DISTNAME=	qcheck
PKGNAME=	qcheck-1.0
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.meanmachine.ch/pub/unix/qmail/

MAINTAINER=	zuntum@NetBSD.org
COMMENT=	Text-only biff with Maildir support

NO_CONFIGURE=	YES

INSTALLATION_DIRS=	bin

do-build:
	${CC} ${CFLAGS} ${WRKSRC}/qcheck.c -o ${WRKSRC}/qcheck

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/qcheck ${PREFIX}/bin/qcheck

.include "../../mk/bsd.pkg.mk"
