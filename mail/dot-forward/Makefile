# $NetBSD: Makefile,v 1.4 2002/01/21 19:02:33 zuntum Exp $
#

DISTNAME=		dot-forward-0.71
PKGREVISION=		1
CATEGORIES=		mail
MASTER_SITES=		http://cr.yp.to/software/

MAINTAINER=		zuntum@netbsd.org
HOMEPAGE=		http://cr.yp.to/dot-forward.html
COMMENT=		get qmail to use .forward files

DEPENDS+=		qmail>=1.03nb1:../../mail/qmail

ALL_TARGET=		it
INSTALL_TARGET=		setup check

.include "../../mk/bsd.prefs.mk"

NO_MTREE=	YES
LOCALBASE=	/

RESTRICTED=		"unsure of djb's license"
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}

post-patch:
	${ECHO} ${CC} ${CFLAGS} > ${WRKSRC}/conf-cc
	${ECHO} ${CC} ${STRIPFLAG} > ${WRKSRC}/conf-ld
	${ECHO} ${QMAILDIR} > ${WRKSRC}/conf-qmail

.include "../../mk/bsd.pkg.mk"
