# $NetBSD: Makefile,v 1.1.1.1.2.1 2002/06/23 18:52:03 jlam Exp $
#

DISTNAME=		qmailanalog-0.70
CATEGORIES=		mail
MASTER_SITES=		http://cr.yp.to/software/

MAINTAINER=		zuntum@netbsd.org
HOMEPAGE=		http://cr.yp.to/qmailanalog.html
COMMENT=		collection of tools to help analyze qmail's activity

ALL_TARGET=		it
INSTALL_TARGET=		setup check

RESTRICTED=		"unsure of djb's license"
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

pre-build:
	${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	${ECHO} ${CC} ${_STRIPFLAG_CC} > ${WRKSRC}/conf-ld
	${ECHO} ${PREFIX}/qmailanalog > ${WRKSRC}/conf-home

.include "../../mk/bsd.pkg.mk"
