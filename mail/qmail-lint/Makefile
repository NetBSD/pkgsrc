# $NetBSD: Makefile,v 1.7 2004/07/22 00:06:40 schmonz Exp $
#

DISTNAME=	qmail-lint-0.55
PKGREVISION=	1
CATEGORIES=	mail
MASTER_SITES=	http://qmail.obeer.com/
EXTRACT_SUFX=	#

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://www.qmail.org/
COMMENT=	Examine the qmail configuration for common errors

EXTRACT_CMD=	${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}

WRKSRC=		${WRKDIR}
USE_PERL5=	yes
REPLACE_PERL=	${DISTNAME}
NO_BUILD=	yes

SUBST_CLASSES+=		qmaildir
SUBST_STAGE.qmaildir=	do-configure
SUBST_FILES.qmaildir=	${DISTNAME}
SUBST_SED.qmaildir=	-e 's|/var/qmail|${QMAILDIR}|g'

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/qmail-lint

.include "../../mk/bsd.pkg.mk"
