# $NetBSD: Makefile,v 1.13 2004/12/03 15:15:02 wiz Exp $
#

DISTNAME=		dot-forward-0.71
PKGREVISION=		2
CATEGORIES=		mail
MASTER_SITES=		http://cr.yp.to/software/

MAINTAINER=		schmonz@NetBSD.org
HOMEPAGE=		http://cr.yp.to/dot-forward.html
COMMENT=		Reads sendmail's .forward files under qmail

DEPENDS+=		qmail>=1.03nb7:../../mail/qmail

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
