# $NetBSD: Makefile,v 1.26 2023/11/15 16:46:38 schmonz Exp $
#

DISTNAME=	qmail-lint-0.55
PKGREVISION=	11
CATEGORIES=	mail
MASTER_SITES=	${HOMEPAGE}
EXTRACT_SUFX=	#

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	https://qmail.notqmail.org/
COMMENT=	Examine the qmail configuration for common errors

WRKSRC=		${WRKDIR}
USE_TOOLS+=	perl:run
REPLACE_PERL=	${DISTNAME}
NO_BUILD=	yes

SUBST_CLASSES+=		qmaildir
SUBST_STAGE.qmaildir=	do-configure
SUBST_FILES.qmaildir=	${DISTNAME}
SUBST_SED.qmaildir=	-e 's|/var/qmail|${QMAILDIR}|g'

INSTALLATION_DIRS=	bin
BUILD_DEFS+=		QMAILDIR

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} \
		${DESTDIR}${PREFIX}/bin/qmail-lint

.include "../../mk/bsd.pkg.mk"
