# $NetBSD: Makefile,v 1.4 2002/01/21 18:53:52 zuntum Exp $
#

DISTNAME=		ezmlm-0.53
CATEGORIES=		mail
MASTER_SITES=		http://cr.yp.to/software/

MAINTAINER=		zuntum@netbsd.org
HOMEPAGE=		http://cr.yp.to/ezmlm.html
COMMENT=		easy-to-use, high-speed mailing list manager for qmail

DEPENDS+=		qmail>=1.03:../../mail/qmail

ALL_TARGET=		it man
INSTALL_TARGET=		setup

RESTRICTED=		"unsure of djb's license"
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

post-patch:
	${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	${ECHO} ${CC} ${STRIPFLAG} > ${WRKSRC}/conf-ld
	${ECHO} ${PREFIX}/bin > ${WRKSRC}/conf-bin
	${ECHO} ${PREFIX}/man > ${WRKSRC}/conf-man
	${ECHO} ${QMAILDIR} > ${WRKSRC}/conf-qmail

.include "../../mk/bsd.pkg.mk"
