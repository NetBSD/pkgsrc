# $NetBSD: Makefile,v 1.8 2005/06/16 06:58:02 jlam Exp $
#

DISTNAME=	autorespond-2.0.5
CATEGORIES=	mail
MASTER_SITES=	${HOMEPAGE}

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://www.inter7.com/devel/
COMMENT=	Simple autoresponder add-on package for qmail

DEPENDS+=	qmail>=1.03:../../mail/qmail


SUBST_CLASSES+=		qmaildir
SUBST_STAGE.qmaildir=	do-configure
SUBST_FILES.qmaildir=	autorespond.c
SUBST_SED.qmaildir=	-e 's|/var/qmail|${QMAILDIR}|g'

INSTALLATION_DIRS=	bin man/man1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/autorespond ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/autorespond.1 ${PREFIX}/man/man1
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/autorespond
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/autorespond
	${INSTALL_DATA} ${WRKSRC}/qmail-auto ${PREFIX}/share/doc/autorespond

.include "../../mk/bsd.pkg.mk"
