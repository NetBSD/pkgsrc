# $NetBSD: Makefile,v 1.1.1.1 2000/12/05 12:48:36 abs Exp $
#

DISTNAME=	bulk_mailer-1.13
CATEGORIES=	mail
MASTER_SITES=	ftp://cs.utk.edu/pub/moore/bulk_mailer/

MAINTAINER=	abs@netbsd.org

HAS_CONFIGURE=	YES
ALL_TARGET=	bulk_mailer

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bulk_mailer ${PREFIX}/bin/bulk_mailer
	${INSTALL_MAN} ${WRKSRC}/bulk_mailer.1 ${PREFIX}/man/man1/bulk_mailer.1

.include "../../mk/bsd.pkg.mk"
