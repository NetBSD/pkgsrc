# $NetBSD: Makefile,v 1.4 2003/07/17 21:46:56 grant Exp $
#

DISTNAME=	qmail-lint-0.55
PKGREVISION=	1
WRKSRC=		${WRKDIR}
CATEGORIES=	mail
MASTER_SITES=	http://qmail.obeer.com/
EXTRACT_SUFX=	#

MAINTAINER=	zuntum@NetBSD.org
HOMEPAGE=	http://www.qmail.org/
COMMENT=	examine the qmail configuration to see if any common errors exist

EXTRACT_CMD=	${CP} ${DOWNLOADED_DISTFILE} ${WRKSRC}

USE_PERL5=	yes
REPLACE_PERL=	${DISTNAME}
NO_BUILD=	yes

post-patch:
	${SED} "s,/var/qmail,${QMAILDIR}," ${WRKSRC}/${DISTNAME}	\
		> ${WRKSRC}/${DISTNAME}.done
	${MV} ${WRKSRC}/${DISTNAME}.done ${WRKSRC}/${DISTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin/qmail-lint

.include "../../mk/bsd.pkg.mk"
