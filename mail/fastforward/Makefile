# $NetBSD: Makefile,v 1.2 2002/01/15 13:49:49 zuntum Exp $
#

DISTNAME=		fastforward-0.51
CATEGORIES=		mail
MASTER_SITES=		http://cr.yp.to/software/

MAINTAINER=		zuntum@netbsd.org
HOMEPAGE=		http://cr.yp.to/fastforward.html
COMMENT=		/etc/aliases support for qmail

DEPENDS+=		qmail>=1.03:../../mail/qmail

ALL_TARGET=		it
INSTALL_TARGET=		setup check

IS_INTERACTIVE=		YES

RESTRICTED=		"unsure of djb's license"
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

post-patch:
	${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	${ECHO} ${CC} ${STRIPFLAG} > ${WRKSRC}/conf-ld

.include "../../mk/bsd.pkg.mk"
