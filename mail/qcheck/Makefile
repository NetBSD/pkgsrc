# $NetBSD: Makefile,v 1.1.1.1 2001/03/12 09:05:45 zuntum Exp $
#

DISTNAME=	qcheck
PKGNAME=	qcheck-1.0
CATEGORIES=	mail
MASTER_SITES=	ftp://ftp.meanmachine.ch/pub/unix/qmail/

MAINTAINER=	zuntum@netbsd.org
COMMENT=	Text-only biff by David Gerber _with Maildir support_

NO_CONFIGURE=	YES

do-build:
	${CC} ${CFLAGS} ${WRKDIR}/qcheck/qcheck.c -o ${WRKDIR}/qcheck/qcheck

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/qcheck/qcheck ${PREFIX}/bin/qcheck

.include "../../mk/bsd.pkg.mk"
