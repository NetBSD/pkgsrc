# $NetBSD: Makefile,v 1.1.1.1 2001/06/27 18:26:54 nra Exp $
# FreeBSD: ports/mail/xmailwatcher/Makefile,v 1.1 2001/03/09 22:31:32 sada Exp

DISTNAME=		xmailwatcher
PKGNAME=		${DISTNAME}-1.6
CATEGORIES=		mail
MASTER_SITES=		ftp://ftp.dcs.ed.ac.uk/pub/X11/

MAINTAINER=		packages@NetBSD.org
COMMENT= 		Mailbox checker which displays sender and subject lines of mails

USE_IMAKE=		yes

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/xmailwatcher
	${INSTALL_DATA} ${WRKSRC}/xmailwatcher.1.html \
		${PREFIX}/share/xmailwatcher
	${INSTALL_PROGRAM} ${WRKSRC}/xmailwatcher ${PREFIX}/bin
	strip ${PREFIX}/bin/xmailwatcher

.include "../../mk/bsd.pkg.mk"
