# $NetBSD: Makefile,v 1.25 2022/06/28 11:34:33 wiz Exp $
#

DISTNAME=	qmail-lint-0.55
PKGREVISION=	11
CATEGORIES=	mail
MASTER_SITES=	${HOMEPAGE}
EXTRACT_SUFX=	#

MAINTAINER=	schmonz@NetBSD.org
HOMEPAGE=	http://qmailorg.schmonz.com/
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
