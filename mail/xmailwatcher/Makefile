# $NetBSD: Makefile,v 1.5 2005/06/16 06:58:08 jlam Exp $

DISTNAME=		xmailwatcher
PKGNAME=		${DISTNAME}-1.6
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.dcs.ed.ac.uk/pub/X11/

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT= 		Mailbox checker which displays sender and subject lines of mails

USE_IMAKE=		yes
INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_DATA} ${WRKSRC}/xmailwatcher.0 ${PREFIX}/man/man1/xmailwatcher.1
	${INSTALL_PROGRAM} ${WRKSRC}/xmailwatcher ${PREFIX}/bin
	strip ${PREFIX}/bin/xmailwatcher

.include "../../mk/bsd.pkg.mk"
