# $NetBSD: Makefile,v 1.7 2005/03/13 03:25:44 schmonz Exp $
#

DISTNAME=		qmailanalog-0.70
CATEGORIES=		mail
MASTER_SITES=		http://cr.yp.to/software/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/qmailanalog.html
COMMENT=		Collection of tools to help analyze qmail's activity

USE_BUILDLINK3=		yes

BUILD_TARGET=		it
INSTALL_TARGET=		setup check

RESTRICTED=		"modified source and binaries may not be distributed"
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

do-configure:
	${ECHO} ${CC:Q} ${CFLAGS:Q} > ${WRKSRC}/conf-cc
	${ECHO} ${CC:Q} ${_STRIPFLAG_CC} > ${WRKSRC}/conf-ld
	${ECHO} ${PREFIX}/qmailanalog > ${WRKSRC}/conf-home

.include "../../mk/bsd.pkg.mk"
