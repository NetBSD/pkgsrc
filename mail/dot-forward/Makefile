# $NetBSD: Makefile,v 1.2 2002/01/15 13:49:48 zuntum Exp $
#

DISTNAME=		dot-forward-0.71
CATEGORIES=		mail
MASTER_SITES=		http://cr.yp.to/software/

MAINTAINER=		zuntum@netbsd.org
HOMEPAGE=		http://cr.yp.to/dot-forward.html
COMMENT=		get qmail to use .forward files

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
	${ECHO} ${LOCALBASE}/qmail > ${WRKSRC}/conf-qmail

.include "../../mk/bsd.pkg.mk"
