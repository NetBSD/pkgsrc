# $NetBSD: Makefile,v 1.10 2004/12/03 15:15:02 wiz Exp $
#

DISTNAME=		fastforward-0.51
PKGREVISION=		2
CATEGORIES=		mail
MASTER_SITES=		http://cr.yp.to/software/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/fastforward.html
COMMENT=		Sendmail-style /etc/aliases support for qmail

DEPENDS+=		qmail>=1.03nb7:../../mail/qmail

CONFLICTS+=		postfix-[0-9]* sendmail-[0-9]*

USE_BUILDLINK3=		yes

BUILD_TARGET=		it install instcheck
INSTALL_TARGET=		setup check

RESTRICTED=		"modified source and binaries may not be distributed"
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

do-configure:
	${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	${ECHO} ${CC} ${_STRIPFLAG_CC} > ${WRKSRC}/conf-ld
	${ECHO} ${QMAILDIR} > ${WRKSRC}/conf-qmail

.include "../../mk/bsd.pkg.mk"
